import java.awt.*;
import javax.swing.*;
public class Player extends JLabel{
    private int x, y,size;
    private boolean left, right, up, down;
    private JLabel label;
    public Player(){
        x = 500;  
        y = 350;
        size = 17;
    }
    public void reset(){
        x= 500;
        y = 350;
    }
    public boolean isDone(){
        if(y>=575)
        return true;
        return false    ;
    }
    public boolean bounceCheck()
    {
        for(Cube s: Game.cubes){
            if(getLeft() < s.getX() + s.getxSize() && getRight() > s.getX() && getTop() < s.getY() + s.getySize() && getBottom() > s.getY())
            {
                return true;
            }
        }
        if(getLeft() < Game.wall.getX() + Game.wall.getxSize() && getRight() > Game.wall.getX() && getTop() < Game.wall.getY() + Game.wall.getySize() && getBottom() > Game.wall.getY())
            {
                if(!Game.key3.collide())
                return true;
            }
        return false;
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
        page.setColor(Color.RED);
        page.fillOval(x,y,size,size);
    }
    public void move(){
        //remove after debug is finished
        if(right == true && x < Game.WIDTH - size){
            x+=1;
            if(bounceCheck())
            x-=1;
        }
        else if(left == true && x > 0){
            x-=1;
            if(bounceCheck())
            x+=1;
        }
        if(down == true && y < Game.HEIGHT - (size)){
            y+=1;
            if(bounceCheck())
            y-=1;
        }
        else if(up == true && y > 0 ){
            y-=1;
            if(bounceCheck())
            y+=1;
        }
        this.setLocation(x,y);
    }
    //sets movement for baby
    public void setLeft(boolean t){
        left = t;
    }
    public void setRight(boolean t){
        right = t;
    }
    public void setDown(boolean t){
        down = t;
    }
    public void setUp(boolean t){
        up = t;
    }
}