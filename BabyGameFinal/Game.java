import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.awt.image.*;
public class Game extends JPanel implements KeyListener{
    public Player player;
    private Cannon cannon;
    public static int WIDTH = 1000;
    public static int HEIGHT = 700;
    private Image park1, park2;
    private JLabel label, label2, endgame;
    public Game(){
        player = new Player();
        cannon = new Cannon();
        label = new JLabel("Distance Travelled: " + player.distance + "feet");
        label.setSize(50,100);
        label.setBounds(300,0, 500,100);
        label.setFont(new java.awt.Font("SansSerif", Font.BOLD, 30));
        label.setForeground(Color.RED);
        label2 = new JLabel("Hold and release Space to launch Baby");
        label2.setBounds(350,0, 500,150);
        label2.setFont(new java.awt.Font("SansSerif", Font.BOLD, 15));
        label2.setForeground(Color.ORANGE);
        endgame = new JLabel("Press Enter to play again");
        endgame.setBounds(200,0, 700,400);
        endgame.setFont(new java.awt.Font("SansSerif", Font.BOLD, 50));
        endgame.setForeground(Color.ORANGE);
        this.add(cannon);
        this.add(label);
        this.add(label2);
        setLayout(null);
        setBackground( Color.BLUE);
        setPreferredSize(new Dimension(WIDTH,HEIGHT));
        this.add(player);
        try{
            getFileImage("babypark.jpg");
            }catch( Exception ex ){}
        addKeyListener( this);
        setFocusable(true);
    }

    private void  getFileImage( String fileName) throws InterruptedException, IOException{
        FileInputStream in = new FileInputStream( fileName);
        byte[] b = new byte[in.available()];
        in.read(b);
        in.close();
        park1 = Toolkit.getDefaultToolkit().createImage(b);
        park2 = Toolkit.getDefaultToolkit().createImage(b);
        MediaTracker mt = new MediaTracker(this);
        mt.addImage( park2, 0);
        mt.addImage( park1, 0);
        mt.waitForAll();
    }
    public void go(){
        while(true){   
        player.move();
        cannon.move(player);
        label.setText("Distance Travelled: " + player.distance + " feet!");
        if(player.launchx == 0 && player.bounce == true && player.end == false){
            this.add(endgame);
            player.end = true;
            player.babyLaugh.play();
        }
        if(player.newGame == true){
            this.remove(endgame);
            player.babyLaugh.stop();
            player.newGame = false;
        }
        try
        {
            Thread.sleep(10);
        }catch( InterruptedException ex){}
        this.repaint();
    }
    }
    public void paintComponent(Graphics page){
        super.paintComponent(page);
        page.drawImage( park2,999 + player.backx, player.backy, this);
        page.drawImage( park1,player.backx, player.backy, this);
        player.draw(page);
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
        if (event.getKeyCode() == KeyEvent.VK_SPACE){
            player.setBarDone(true);
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
        if (event.getKeyCode() == KeyEvent.VK_SPACE){
            player.setBar(true);
        }
        if (event.getKeyCode() == KeyEvent.VK_ENTER && player.end == true){
            player.newGame = true;
        }
        this.repaint();
        
    }
    public void keyTyped(KeyEvent event){
        
    }
}