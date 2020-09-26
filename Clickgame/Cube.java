import java.awt.*;
import javax.swing.*;
import java.io.*;
public class Cube extends Shape{
    private ImageIcon face;
    public Cube(ImageIcon m){
        face = m;
        this.setBounds(super.getX(),super.getY(),super.setWidth(face.getIconWidth()),super.setHeight(face.getIconHeight()));
        this.setIcon(face);
    }
    public void draw(Graphics page){
        //page.setColor(color);
        //page.fillRect(super.getX(),super.getY(),super.getWidth(),super.getWidth());
    }
}