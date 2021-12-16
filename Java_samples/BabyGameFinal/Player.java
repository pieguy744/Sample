import java.awt.*;
import javax.swing.*;
public class Player extends JLabel{
    private int x, y, rx, ry, size,launchSpeed, bounceCount, sizzledo, countEnd = 0;
    public int backx, backy, launchx, distance = 0;
    private double launchy = 0;
    private boolean left, right, up, down, bar, barUp, barDown, barDone;
    public boolean end, bounce, launchStart, newGame;
    private ImageIcon baby;
    private JLabel label;
    public Sound sizzle,fart, babyLaugh,iceCream, cannon; 
    public void launch(){
        y -= launchy;
        launchy -= .25;
        if(x<=450){
            x+=launchx;
            backx -= launchx;
        }
        else{
            backx -= (int)(launchx*1.5);
        }
        if(backx <=-1000){
            backx += 1000;
        }
        
    }
    public void bounce(){
        bounceCount++;
        fart.play();
        if(bounceCount <= 3){
            launchSpeed = (int)(Math.sqrt(launchy*launchy + launchx*launchx) * .75);
            launchy = Math.abs(launchy);
            launchy = (int)(launchSpeed*Math.sqrt(2)/2);
            launchx = (int)(launchSpeed*Math.sqrt(2)/2);
        }
        else{
            launchy = 5 - countEnd;
            launchx *=.75;
            x+=launchx;
            if(countEnd <= 5){
                countEnd++;
            }
            if(launchx == 0){
                countEnd = 5;
                bounce = true;
            }
        }
    }
    public Player(){
        x = 120;
        y = 450;
        rx = 250;
        ry = 601;
        sizzledo = 0;
        barUp = true;
        size = 100;
        baby = new ImageIcon("baby.png");
        this.setBounds(x,y,size,size);
        this.setIcon(baby);
        sizzle = new Sound("Fuse Burning.wav");
        fart = new Sound("fart.wav");
        babyLaugh = new Sound("Giggles-SoundBible.com-710042657.wav");
        iceCream = new Sound("ice.wav");
        cannon = new Sound("cannon.wav");
        //iceCream.loop();
        
    }
    public int getLeft(){
        return x;
    }
    public int getRight(){
        return x + size;
    }
    public int getTop(){
        return y;
    }
    public int getBottom(){
        return y + size;
    }
    //sends baby to random position on screen. remove after debug
    public void randomPosition(){
        x = (int)(Math.random()*Game.WIDTH);
        y = (int)(Math.random()*Game.HEIGHT);
        this.setLocation( x, y );
    }
    public void draw(Graphics page){
        //page.setColor(color);
        //page.fillOval(x,y,size,size);
        //makes powerbar
        page.setColor(Color.ORANGE);
        page.fillRect(250,600,500,50);
        page.setColor(Color.RED);
        page.fillRect(rx,ry,10,48);
    }
    public void move(){
        //remove after debug is finished
        if(right == true && x < Game.WIDTH - size){
            x+=10;
        }
        else if(left == true && x > 0){
            x-=10;
        }
        if(up == true && y < Game.HEIGHT - size){
            y+=10;
        }
        else if(down == true && y > 0){
            y-=10;
        }
        //controls launchbar
        if (bar == true && sizzledo == 0){
            sizzle.loop();
            sizzledo = 1;
        }
        if(barDone == true && sizzledo == 1){
            sizzle.stop();
            sizzledo = 2;
        }
        
        
        if(bar == true && rx < 750 && barUp == true && barDone == false){
            rx+=10;
            if(rx == 750){
                barUp = false;
                barDown = true;
            }
        }
        if(bar == true && rx > 250 && barDown == true && barDone == false){
            rx-=10;
            if(rx == 250){
                barUp = true;
                barDown = false;
            }
        }
        //sets baby velocity
        if(barDone == true && launchStart == false){
        launchSpeed = (rx-250)/15;
        launchy = (int)(launchSpeed*Math.sqrt(2)/2);
        launchx = (int)(launchSpeed*Math.sqrt(2)/2);
        cannon.play();
        launchStart = true;
        }
        //starts babylaunch
        if(launchStart == true && y <= 500){
            launch();
        }
        //bounce
        if(launchStart == true && y >= 500 && bounce == false) {
            y = 500;
            bounce();
        }
        
        if (newGame == true){
        x = 120;
        y = 450;
        rx = 250;
        ry = 601;
        barUp = true;
        barDown = false;
        end = false;
        bounce = false;
        launchStart = false;
        bar = false;
        barDone = false;
        backx = 0;
        backy = 0;
        launchSpeed =0;
        bounceCount = 0;
        countEnd = 0;
        launchx = 0;
        distance = 0;
        launchy = 0;
        Cannon.x = 0;
        sizzledo = 0;
        }
        this.setLocation(rx,ry);
        this.setLocation(x,y);
        distance += launchx;
    }
    
    //sets movement for baby
    public void setLeft(boolean t){
        left = t;
    }
    public void setRight(boolean t){
        right = t;
    }
    public void setDown(boolean t){
        up = t;
    }
    public void setUp(boolean t){
        down = t;
    }
    //sets movement for powerbar
    public void setBar(boolean t){
        bar = t;
    }
    public void setBarDone(boolean t){
        barDone = t;
    }
    }