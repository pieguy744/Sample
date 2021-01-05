import java.awt.*;
import javax.swing.*;
import java.io.*;
public class Rect extends JLabel{
    private int x,y,size;
    private Color color;
    public Rect(){
        x = (int)(Math.random()*Game.WIDTH);
        y = (int)(Math.random()*Game.HEIGHT);
        color = Color.RED;
        size = 100;
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public int getWidth(){
        return size;
    }
    public int getLength(){
        return size;
    }
    public void draw(Graphics page){
        page.setColor(color);
        page.fillRect(x,y,size,size);
    }
}