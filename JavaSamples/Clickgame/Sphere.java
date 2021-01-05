import java.awt.*;
import javax.swing.*;
import java.io.*;
public class Sphere extends Shape{
    private ImageIcon face;
    public Sphere(ImageIcon m){
        face = m;
        this.setBounds(super.getX(),super.getY(),super.setWidth(face.getIconWidth()),super.setHeight(face.getIconHeight()));
        this.setIcon(face);
    }
    public void draw(Graphics page){
         //page.setColor(Color.RED);
         //page.fillOval(super.getX(),super.getY(),super.getWidth(),super.getWidth());
    }
    public boolean isCircle(){
        return true;
    }
}