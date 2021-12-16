//Cube Class
import java.util.ArrayList;
import java.util.List;
import java.io.*;
import java.awt.*;
public class Cube
{
    private int xPos,yPos; 
    private int xSize,ySize;
    private Color color;
    
    public Cube(int a, int b, int c, int d){
        xPos=a;
        yPos=b;
        xSize=c;
        ySize=d;
        
        color=Color.BLACK;
    }
    public Color getColor(){
        return color;
    }
    public void setColor(Color c){
     color = c;   
    }
    public void draw(Graphics page){
        
        page.setColor(color);
        page.fillRect(xPos, yPos, xSize, ySize);
    }
    
    public int getX(){
        return xPos;
    }
    public int getY(){
        return yPos;
    }
    public int getxSize(){
        return xSize;
    }
    public int getySize(){
        return ySize;
    }
}