import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.awt.image.*;
import java.util.ArrayList;
public class Game extends JPanel implements KeyListener{
    public static Player player;
    public static ArrayList<Cube> cubes = new ArrayList<Cube>();
    public static Key key1 = new Key(734,98,16,16, Color.GREEN), key2 = new Key(253,78,16,16,Color.PINK), key3 = new Key (734,559,16,17,Color.YELLOW), wall = new Key(250,575,80,3,Color.GREEN);
    public static final int WIDTH = 1000, HEIGHT = 700;
    public static ArrayList<Sound> holmTaunt = new ArrayList<Sound>();
    private Sound finish = new Sound("finish.wav");
    private Image park2;
    private JLabel label, label2, endgame;
    private boolean gameDone;
    public Game(){
        player = new Player();
        makeMaze();
        label = new JLabel( "" + player.getTop() );
        //this.add( label );
        //label.setVisible( true );
        label.setFont( new Font( "Arial", Font.BOLD, 30 ) );
        label.setBounds( 400, 30, 200, 30 );
        label.setHorizontalAlignment( SwingConstants.CENTER );
        label.setForeground( Color.WHITE );
        for(int i = 1; i < 7; i++){
            holmTaunt.add(new Sound("Holm" + i + ".wav"));
        }
        setLayout(null);
        setBackground( Color.BLUE);   
        setPreferredSize(new Dimension(WIDTH,HEIGHT));
        this.add(player);
        player.setVisible(true);
        endgame = new JLabel("Press Entcer to play again");
        endgame.setBounds(200,0, 700,400);
        endgame.setFont(new java.awt.Font("SansSerif", Font.BOLD, 50));
        endgame.setForeground(Color.BLACK);
        try{
            getFileImage("holm3.png");
            }catch( Exception ex ){}
        addKeyListener(this);
        setFocusable(true);
        holmTaunt.remove(2).play();
    }
   
    private void  getFileImage( String fileName) throws InterruptedException, IOException{
        FileInputStream in = new FileInputStream( fileName);
        byte[] b = new byte[in.available()];
        in.read(b);
        in.close();
        park2 = Toolkit.getDefaultToolkit().createImage(b);
        MediaTracker mt = new MediaTracker(this);
        mt.addImage( park2, 0);
        mt.waitForAll();
    }
    public void go(){
        while(true){   
            player.move();
            try
            {
                Thread.sleep(10);
            }catch( InterruptedException ex){}
            if(!player.isDone()){
                this.repaint();
            }
            else if(!gameDone){
                gameDone = true;
                this.add(endgame);
                endgame.setVisible(true);
                finish.play();
            }
            label.setText("" + player.getTop());
        }
    }
    public void reset(){
        player.reset();
        key1.reset();
        key2.reset();
        key3.reset();
        endgame.setVisible(false);
        gameDone = false;
    }
    public void paintComponent(Graphics page){
        super.paintComponent(page);
        page.drawImage( park2,450,270, this);
        player.draw(page);
        if(!key1.collide()){
            key1.draw(page);
            key2.draw(page);
            key3.draw(page);
            wall.draw(page);
        }
        else if(!key2.collide()){
                key2.draw(page);
                key3.draw(page);
                wall.setColor(key2.getColor());
                wall.draw(page);
            }
        else if(!key3.collide()){
                key3.draw(page);
                wall.setColor(key3.getColor());
                wall.draw(page);
        }
        for(Cube r: cubes){
            r.draw(page);
        }
    }
    public void keyReleased(KeyEvent event){
        if(event.getKeyCode() == KeyEvent.VK_P){
            player.randomPosition();
        }
        if(event.getKeyCode() == KeyEvent.VK_LEFT){
            player.setLeft(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_RIGHT){
            player.setRight(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_UP){
            player.setUp(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_DOWN){
            player.setDown(false);
        }
        this.repaint();
    }
    public void keyPressed(KeyEvent event){
        if(event.getKeyCode() == KeyEvent.VK_LEFT){
            player.setLeft(true);
            
            player.setRight(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_RIGHT){
            player.setRight(true);
            player.setLeft(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_UP){
            player.setUp(true);
            player.setDown(false);
        }
        else if(event.getKeyCode() == KeyEvent.VK_DOWN){
            player.setDown(true);
            player.setUp(false);
        }
        if(event.getKeyCode() == KeyEvent.VK_ENTER && gameDone){
            reset();
        }
        this.repaint();
        
    }
    public void keyTyped(KeyEvent event){
        
    }
     public void makeMaze(){
        //walls
        cubes.add(new Cube(250,75,3,500));
        cubes.add(new Cube(250,75,500,3));
        cubes.add(new Cube(330,575,423,3));
        cubes.add(new Cube(750,75,3,500));
        //starting box
        cubes.add(new Cube(450,275,3,40));
        cubes.add(new Cube(450,355,3,20));
        cubes.add(new Cube(550,275,3,20));
        cubes.add(new Cube(550,335,3,40));
        cubes.add(new Cube(450,275,43,3));
        cubes.add(new Cube(530,275,23,3));
        cubes.add(new Cube(450,375,23,3));
        cubes.add(new Cube(510,375,43,3));        
        //All boxes are 20 apart
        //y axis
        cubes.add(new Cube(270,175,3,20));
        cubes.add(new Cube(270,295,3,40));
        cubes.add(new Cube(270,455,3,60));
        cubes.add(new Cube(290,95,3,40));
        cubes.add(new Cube(290,155,3,60));
        cubes.add(new Cube(290,235,3,60));
        cubes.add(new Cube(290,375,3,20));
        cubes.add(new Cube(290,435,3,40));
        cubes.add(new Cube(290,515,3,20));
        cubes.add(new Cube(310,135,3,20));
        cubes.add(new Cube(310,315,3,140));
        cubes.add(new Cube(310,475,3,20));
        cubes.add(new Cube(310,535,3,20));
        cubes.add(new Cube(330,95,3,20));
        cubes.add(new Cube(330,135,3,120));
        cubes.add(new Cube(330,335,3,80));
        cubes.add(new Cube(330,455,3,20));
        cubes.add(new Cube(330,555,3,20));
        cubes.add(new Cube(350,115,3,20));
        cubes.add(new Cube(350,155,3,20));
        cubes.add(new Cube(350,195,3,20));
        cubes.add(new Cube(350,275,3,80));
        cubes.add(new Cube(350,415,3,20));
        cubes.add(new Cube(350,475,3,60));
        cubes.add(new Cube(370,95,3,20));
        cubes.add(new Cube(370,135,3,60));
        cubes.add(new Cube(370,295,3,20));
        cubes.add(new Cube(370,355,3,100));
        cubes.add(new Cube(370,475,3,40));
        cubes.add(new Cube(390,155,3,20));
        cubes.add(new Cube(390,195,3,20));
        cubes.add(new Cube(390,415,3,120));
        cubes.add(new Cube(410,115,3,60));
        cubes.add(new Cube(410,195,3,20));
        cubes.add(new Cube(410,255,3,40));
        cubes.add(new Cube(410,335,3,40));
        cubes.add(new Cube(410,395,3,20));
        cubes.add(new Cube(410,515,3,20));
        cubes.add(new Cube(430,95,3,20));
        cubes.add(new Cube(430,175,3,20));
        cubes.add(new Cube(430,215,3,40));
        cubes.add(new Cube(430,315,3,40));
        cubes.add(new Cube(430,375,3,20));
        cubes.add(new Cube(430,415,3,80));
        cubes.add(new Cube(430,535,3,20));
        cubes.add(new Cube(450,75,3,20));
        cubes.add(new Cube(450,135,3,40));
        cubes.add(new Cube(450,195,3,40));
        cubes.add(new Cube(450,255,3,20));
        cubes.add(new Cube(450,415,3,20));
        cubes.add(new Cube(450,475,3,60));
        cubes.add(new Cube(470,95,3,20));
        cubes.add(new Cube(470,155,3,40));
        cubes.add(new Cube(470,235,3,20));
        cubes.add(new Cube(470,435,3,40));
        cubes.add(new Cube(470,495,3,60));
        cubes.add(new Cube(490,95,3,60));
        cubes.add(new Cube(490,175,3,100));
        cubes.add(new Cube(490,395,3,40));
        cubes.add(new Cube(490,455,3,20));
        cubes.add(new Cube(490,515,3,20));
        cubes.add(new Cube(510,115,3,20));
        cubes.add(new Cube(510,155,3,80));
        cubes.add(new Cube(510,475,3,40));
        cubes.add(new Cube(510,535,3,40));
        cubes.add(new Cube(530,75,3,40));
        cubes.add(new Cube(530,135,3,20));
        cubes.add(new Cube(530,175,3,40));
        cubes.add(new Cube(530,375,3,60));
        cubes.add(new Cube(530,455,3,20));
        cubes.add(new Cube(530,515,3,40));
        cubes.add(new Cube(550,95,3,60));
        cubes.add(new Cube(550,235,3,40));
        cubes.add(new Cube(550,395,3,60));
        cubes.add(new Cube(550,475,3,20));
        cubes.add(new Cube(550,515,3,60));
        cubes.add(new Cube(570,75,3,20));
        cubes.add(new Cube(570,155,3,40));
        cubes.add(new Cube(570,215,3,20));
        cubes.add(new Cube(570,275,3,120));
        cubes.add(new Cube(570,495,3,60));
        cubes.add(new Cube(590,75,3,100));
        cubes.add(new Cube(590,215,3,80));
        cubes.add(new Cube(590,315,3,40));
        cubes.add(new Cube(590,395,3,40));
        cubes.add(new Cube(590,515,3,20));
        cubes.add(new Cube(610,95,3,20));
        cubes.add(new Cube(610,135,3,20));
        cubes.add(new Cube(610,175,3,40));
        cubes.add(new Cube(610,255,3,60));
        cubes.add(new Cube(610,335,3,100));
        cubes.add(new Cube(610,455,3,60));
        cubes.add(new Cube(610,535,3,20));
        cubes.add(new Cube(630,75,3,20));
        cubes.add(new Cube(630,115,3,20));
        cubes.add(new Cube(630,155,3,20));
        cubes.add(new Cube(630,255,3,160));
        cubes.add(new Cube(630,475,3,20));
        cubes.add(new Cube(630,515,3,20));
        cubes.add(new Cube(630,555,3,20));
        cubes.add(new Cube(650,95,3,60));
        cubes.add(new Cube(650,235,3,20));
        cubes.add(new Cube(650,275,3,40));
        cubes.add(new Cube(650,375,3,60));
        cubes.add(new Cube(650,455,3,20));
        cubes.add(new Cube(650,495,3,20));
        cubes.add(new Cube(670,75,3,60));
        cubes.add(new Cube(670,155,3,40));
        cubes.add(new Cube(670,215,3,20));
        cubes.add(new Cube(670,255,3,80));
        cubes.add(new Cube(670,355,3,60));
        cubes.add(new Cube(670,435,3,20));
        cubes.add(new Cube(670,475,3,20));
        cubes.add(new Cube(670,515,3,20));
        cubes.add(new Cube(670,555,3,20));
        cubes.add(new Cube(690,115,3,40));
        cubes.add(new Cube(690,195,3,20));
        cubes.add(new Cube(690,235,3,20));
        cubes.add(new Cube(690,275,3,20));
        cubes.add(new Cube(690,335,3,60));
        cubes.add(new Cube(690,435,3,40));
        cubes.add(new Cube(690,495,3,20));
        cubes.add(new Cube(690,535,3,40));
        cubes.add(new Cube(710,135,3,140));
        cubes.add(new Cube(710,295,3,20));
        cubes.add(new Cube(710,355,3,40));
        cubes.add(new Cube(710,455,3,40));
        cubes.add(new Cube(710,515,3,40));
        cubes.add(new Cube(730,95,3,20));
        cubes.add(new Cube(730,175,3,20));
        cubes.add(new Cube(730,255,3,40));
        cubes.add(new Cube(730,315,3,40));
        cubes.add(new Cube(730,375,3,100));
        cubes.add(new Cube(730,535,3,40));
        //x axis
        cubes.add(new Cube(270,95,43,3));
        cubes.add(new Cube(330,95,103,3));
        cubes.add(new Cube(490,95,23,3));
        cubes.add(new Cube(690,95,43,3));
        cubes.add(new Cube(250,115,23,3));
        cubes.add(new Cube(310,115,23,3));
        cubes.add(new Cube(370,115,23,3));
        cubes.add(new Cube(430,115,63,3));
        cubes.add(new Cube(510,115,63,3));
        cubes.add(new Cube(590,115,43,3));
        cubes.add(new Cube(690,115,23,3));
        cubes.add(new Cube(730,115,23,3));
        cubes.add(new Cube(250,135,43,3));
        cubes.add(new Cube(310,135,43,3));
        cubes.add(new Cube(370,135,43,3));
        cubes.add(new Cube(430,135,43,3));
        cubes.add(new Cube(570,135,23,3));
        cubes.add(new Cube(670,135,23,3));
        cubes.add(new Cube(710,135,23,3));
        cubes.add(new Cube(270,155,43,3));
        cubes.add(new Cube(410,155,23,3));
        cubes.add(new Cube(470,155,63,3));
        cubes.add(new Cube(550,155,23,3));
        cubes.add(new Cube(590,155,43,3));
        cubes.add(new Cube(650,155,23,3));
        cubes.add(new Cube(730,155,23,3));
        cubes.add(new Cube(250,175,23,3));
        cubes.add(new Cube(290,175,23,3));
        cubes.add(new Cube(350,175,23,3));
        cubes.add(new Cube(390,175,23,3));
        cubes.add(new Cube(430,175,23,3));
        cubes.add(new Cube(530,175,23,3));
        cubes.add(new Cube(630,175,23,3));
        cubes.add(new Cube(670,175,63,3));
        cubes.add(new Cube(310,195,43,3));
        cubes.add(new Cube(370,195,103,3));
        cubes.add(new Cube(550,195,63,3));
        cubes.add(new Cube(630,195,43,3));
        cubes.add(new Cube(250,215,63,3));
        cubes.add(new Cube(350,215,23,3));
        cubes.add(new Cube(470,215,23,3));
        cubes.add(new Cube(530,215,63,3));
        cubes.add(new Cube(610,215,83,3));
        cubes.add(new Cube(710,215,43,3));
        cubes.add(new Cube(270,235,163,3));
        cubes.add(new Cube(450,235,23,3));
        cubes.add(new Cube(510,235,43,3));
        cubes.add(new Cube(590,235,63,3));
        cubes.add(new Cube(730,235,23,3));
        cubes.add(new Cube(250,255,23,3));
        cubes.add(new Cube(290,255,23,3));
        cubes.add(new Cube(330,255,43,3));
        cubes.add(new Cube(390,255,23,3));
        cubes.add(new Cube(430,255,23,3));
        cubes.add(new Cube(490,255,43,3));
        cubes.add(new Cube(550,255,43,3));
        cubes.add(new Cube(650,255,43,3));
        cubes.add(new Cube(250,275,23,3));
        cubes.add(new Cube(310,275,83,3));
        cubes.add(new Cube(410,275,23,3));
        cubes.add(new Cube(630,275,23,3));
        cubes.add(new Cube(690,275,43,3));
        cubes.add(new Cube(270,295,63,3));
        cubes.add(new Cube(370,295,83,3));
        cubes.add(new Cube(250,295,23,3));
        cubes.add(new Cube(290,315,63,3));
        cubes.add(new Cube(370,315,63,3));
        cubes.add(new Cube(590,315,23,3));
        cubes.add(new Cube(670,315,63,3));
        cubes.add(new Cube(270,335,23,3));
        cubes.add(new Cube(350,335,63,3));
        cubes.add(new Cube(650,335,23,3));
        cubes.add(new Cube(690,335,23,3));
        cubes.add(new Cube(250,355,43,3));
        cubes.add(new Cube(370,355,23,3));
        cubes.add(new Cube(590,355,23,3));
        cubes.add(new Cube(630,355,43,3));
        cubes.add(new Cube(710,355,23,3));
        cubes.add(new Cube(250,375,23,3));
        cubes.add(new Cube(330,375,23,3));
        cubes.add(new Cube(390,375,63,3));
        cubes.add(new Cube(550,375,43,3));
        cubes.add(new Cube(270,395,43,3));
        cubes.add(new Cube(330,395,83,3));
        cubes.add(new Cube(450,395,63,3));
        cubes.add(new Cube(570,395,23,3));
        cubes.add(new Cube(690,395,23,3));
        cubes.add(new Cube(250,415,43,3));
        cubes.add(new Cube(410,415,63,3));
        cubes.add(new Cube(510,415,23,3));
        cubes.add(new Cube(550,415,23,3));
        cubes.add(new Cube(630,415,23,3));
        cubes.add(new Cube(670,415,63,3));
        cubes.add(new Cube(270,435,83,3));
        cubes.add(new Cube(390,435,23,3));
        cubes.add(new Cube(470,435,63,3));
        cubes.add(new Cube(570,435,63,3));
        cubes.add(new Cube(650,435,23,3));
        cubes.add(new Cube(690,435,23,3));
        cubes.add(new Cube(250,455,23,3));
        cubes.add(new Cube(330,455,63,3));
        cubes.add(new Cube(410,455,43,3));
        cubes.add(new Cube(490,455,23,3));
        cubes.add(new Cube(530,455,63,3));
        cubes.add(new Cube(610,455,43,3));
        cubes.add(new Cube(670,455,23,3));
        cubes.add(new Cube(710,455,23,3));
        cubes.add(new Cube(290,475,23,3));
        cubes.add(new Cube(350,475,23,3));
        cubes.add(new Cube(390,475,23,3));
        cubes.add(new Cube(450,475,43,3));
        cubes.add(new Cube(510,475,23,3));
        cubes.add(new Cube(550,475,63,3));
        cubes.add(new Cube(290,495,63,3));
        cubes.add(new Cube(410,495,23,3));
        cubes.add(new Cube(470,495,43,3));
        cubes.add(new Cube(530,495,63,3));
        cubes.add(new Cube(610,495,23,3));
        cubes.add(new Cube(650,495,23,3));
        cubes.add(new Cube(690,495,43,3));
        cubes.add(new Cube(270,515,63,3));
        cubes.add(new Cube(410,515,43,3));
        cubes.add(new Cube(490,515,43,3));
        cubes.add(new Cube(590,515,23,3));
        cubes.add(new Cube(630,515,23,3));
        cubes.add(new Cube(690,515,63,3));
        cubes.add(new Cube(250,535,23,3));
        cubes.add(new Cube(310,535,83,3));
        cubes.add(new Cube(610,535,83,3));
        cubes.add(new Cube(270,555,43,3));
        cubes.add(new Cube(330,555,103,3));
        cubes.add(new Cube(450,555,63,3));
        cubes.add(new Cube(570,555,43,3));
        cubes.add(new Cube(630,555,23,3));
        cubes.add(new Cube(250,555,23,3));
    }
}