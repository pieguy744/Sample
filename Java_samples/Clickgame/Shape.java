import java.awt.*;
import javax.swing.*;
import java.io.*;
public class Shape extends JLabel{
    private int x,y,xShift,yShift, width, height;
    private Color color;
    private boolean right, left, down, up;
    public Shape(){
        x = (int)(Math.random()*ClickGame.WIDTH);
        y = (int)(Math.random()*ClickGame.HEIGHT);
        xShift = 1;
        yShift = 1;
        int coin1 = (int)(Math.random()*2)+1;
        int coin2 = (int)(Math.random()*2)+1;
        if(coin1 == 1)
            down = true;
        else 
            up = true;
        if(coin2 == 1)
            left = true;
        else
            right = true;
        //size = (int)(Math.random()*100 + 51);
        width = 160;
        height = 160;
    }
    public void move(){
        if(right == true && x < ClickGame.WIDTH - width){
            x+=xShift;
        }
        else if(left == true && x > 0){
            x-=xShift;
        }
        if(down == true && y < ClickGame.HEIGHT - height){
            y+=yShift;
        }
        else if(up == true && y > 0){
            y-=yShift;
        }
        if(right == true && x >= ClickGame.WIDTH - width){
            right = false;
            left = true;
        }
        if(left == true && x <= 0){
            left = false;
            right = true;
        }
        if(down == true && y >= ClickGame.HEIGHT - height){
            down = false;
            up = true;
        }
        else if(up == true && y <= 0){
            up = false;
            down = true;
        }
        this.setLocation(super.getX(),super.getY());
    }
    public int getX(){
        return x;
    }
    public int setWidth(int w){
        width = w;
        return w;
    }
    public int setHeight(int h){
        height = h;
        return h;
    }
    public int getY(){
        return y;
    }
    public int getWidth(){
        return width;
    }
    public int getHeight(){
        return height;
    }
    public void draw(Graphics page){
        page.setColor(color);
    }
    public boolean isCircle(){
        return false;
    }
}