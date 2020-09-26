import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
public class ClickGame extends JPanel implements MouseListener
{
    public static final int WIDTH = 1200;
    public static final int HEIGHT = 800;
    private JLabel label, Donelabel;
    private ArrayList<ImageIcon> mikey = new ArrayList<ImageIcon>(),holm = new ArrayList<ImageIcon>();
    private int timer = 0, sphereGone = 0, coin =0;
    private ArrayList<Shape> shapes = new ArrayList<Shape>();
    private ArrayList<Sound> taunt = new ArrayList<Sound>(), holmTaunt = new ArrayList<Sound>();
    private Image background;
    //constructor - sets the initial conditions for this Game object
    public ClickGame()
    {
        //make a panel with dimensions WIDTH by HEIGHT with a blue background
        this.setLayout( null );//Don't change
        this.setPreferredSize( new Dimension( WIDTH, HEIGHT ) );//Don't change
        //create and format a JLabel to display a timer
        label = new JLabel( "Time: " + timer );
        this.add( label );
        label.setVisible( true );
        label.setFont( new Font( "Arial", Font.BOLD, 30 ) );
        label.setBounds( 400, 30, 200, 30 );
        label.setHorizontalAlignment( SwingConstants.CENTER );
        label.setForeground( Color.WHITE );
     
        //creates finished Jlabel that says how many mikeys vanquished
        Donelabel = new JLabel();
        this.add( Donelabel );
        Donelabel.setVisible( true );
        Donelabel.setFont( new Font( "Arial", Font.BOLD, 30 ) );
        Donelabel.setBounds( 300,90, 400, 30 );
        Donelabel.setHorizontalAlignment( SwingConstants.CENTER );
        Donelabel.setForeground( Color.WHITE );
     
        
        try{
            getFileImage("comproom.jpg");
            }catch( Exception ex ){}
        //adds mikeys
        for(int i = 1; i < 7; i++){
            mikey.add(new ImageIcon("mikey" + i + ".png"));
        }
        //Add holms
        for(int i = 1; i < 7; i++){
            holm.add(new ImageIcon("holm" + i + ".png"));
        }
        //add mikeyTaunt
        for(int i = 1; i < 7; i++){
            taunt.add(new Sound("taunt" + i + ".wav"));
        }
        for(int i = 1; i < 7; i++){
            holmTaunt.add(new Sound("Holm" + i + ".wav"));
        }
        this.addMouseListener(this);
    
        this.setFocusable(true);//I'll tell you later - Don't change
    }
    //pre:
    //post: returns random color of the six colors
    
    private void  getFileImage( String fileName) throws InterruptedException, IOException{
        FileInputStream in = new FileInputStream( fileName);
        byte[] b = new byte[in.available()];
        in.read(b);
        in.close();
        background = Toolkit.getDefaultToolkit().createImage(b);
        MediaTracker mt = new MediaTracker(this);
        mt.addImage( background, 0);
        mt.waitForAll();
    }
    
    //pre:
    //post:creates and adds a new sphere object to Arraylist
    public void newSphere(){
        shapes.add( new Sphere(mikey.get((int)(Math.random()*6))));
        this.add(shapes.get(shapes.size()-1));
    }
    //pre:
    //post:creates and adds a new rectangle object to Arraylist
    public void newCube(){
        shapes.add( new Cube(holm.get((int)(Math.random()*6))));
        this.add(shapes.get(shapes.size()-1));
    }
    //This is the method that runs the game
    public void playGame()
    {
        //sets difficulty level
        Scanner scan = new Scanner(System.in);
        System.out.println("Welcome to Mike Away! Please enter your difficulty level.");
        System.out.println("Easy: 1");
        System.out.println("Medium: 2");
        System.out.println("Hard: 3");
        System.out.println("Insane: 4");
        int co = scan.nextInt();
        boolean configE = false;
        boolean configM = false;
        boolean configH = false;
        boolean configI = false;
        if(co == 1){
            configE = true;
        }
        else if(co == 2){
            configM = true;
        }
        else if(co == 3){
            configH = true;
        }
        else if(co == 4){
            configI = true;
        }
        boolean over = false;
        while( !over )
        {
            try
            {
                Thread.sleep( 10 );//pause for 10 milliseconds
                timer += 10;
                label.setText( "Time: " + timer/1000 );
            }catch( InterruptedException ex ){}
            //different levels of difficulty changes the interval between new shapes
            if(configM == true){
                if(timer%2000 == 0){
                    coin = (int)(Math.random()*2)+1;
                    if(coin == 1)
                        newSphere();
                    else
                        newCube();
                    }
            }
            else if(configE == true){
                if(timer%4000 == 0){
                coin = (int)(Math.random()*2)+1;
                if(coin == 1)
                    newSphere();
                else
                    newCube();
                }
            }
            else if(configH == true){
                if(timer%1000 == 0){
                coin = (int)(Math.random()*2)+1;
                if(coin == 1)
                    newSphere();
                else
                    newCube();
                }
            }
            //insane config gives sphere slightly greater chance of spawning than cube
            else if(configI == true){
                if(timer%500 == 0){
                coin = (int)(Math.random()*6)+1;
                if(coin == 1 || coin == 3 || coin == 4 || coin == 5)
                    newSphere();
                else
                    newCube();
                }
            }
            for(Shape s: shapes){
                s.move();
            }
            if(countSpheres() == 5){
                over = true;
                Donelabel.setText("Mikeys Vanquished: " + sphereGone);
                for(int i = shapes.size()-1; i >= 0; i--){
                    this.remove(shapes.remove(i));
                }
            }
            this.repaint();//redraw the screen with the updated locations; calls paintComponent below
        }
    }
    
    //Precondition: executed when repaint or paintImmediately is called
    //Postcondition: the screen has been updated
    public void paintComponent( Graphics page )
    {
        super.paintComponent( page );
        page.drawImage(background,0,0,this);
        for(Shape s: shapes){
            s.draw(page);
        }
    }
    //pre:
    //post: count all spheres in existence
    public int countSpheres(){
        int sphereCount = 0;
        for(Shape s: shapes){
            if(s.isCircle())
            sphereCount++;
        }
        return sphereCount;
    }
     
    //this method is called whenever the mouse button is pressed
    public void mousePressed( MouseEvent event )
    {
        int mouseX = event.getX(); //returns the x coordinate of the cursor when the mouse is clicked
        int mouseY = event.getY(); //returns the y coordinate of the cursor when the mouse is clicked
        for(int i = shapes.size()-1; i >= 0; i--){
            if(Math.sqrt((mouseX-shapes.get(i).getX() - shapes.get(i).getWidth()/2)*(mouseX-shapes.get(i).getX() - shapes.get(i).getWidth()/2) + (mouseY-shapes.get(i).getY() - shapes.get(i).getHeight()/2)*(mouseY-shapes.get(i).getY() - shapes.get(i).getHeight()/2)) < shapes.get(i).getHeight()/2)
            {
                if(shapes.get(i).isCircle()){
                    this.remove(shapes.remove(i));
                    sphereGone++;
                    taunt.get((int)(Math.random()*6)).play();
                
                    
                }
                else{
                    holmTaunt.get((int)(Math.random()*6)).play();
                }
            }
        }
    }
    
    //required for compiling; do not use
    public void mouseClicked( MouseEvent event )
    {
    }
    //required for compiling; do not use
    public void mouseReleased( MouseEvent event )
    {}
    //required for compiling; do not use
    public void mouseEntered( MouseEvent event )
    {}
    //required for compiling; do not use
    public void mouseExited( MouseEvent event )
    {}
}
