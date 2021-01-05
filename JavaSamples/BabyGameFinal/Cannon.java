import java.awt.*;
import javax.swing.*;
public class Cannon extends JLabel{
    private ImageIcon cannon;
    public static int x;
    public Cannon(){
        cannon = new ImageIcon("Cannon.png");
        x = 0;
        this.setBounds(x,550,300,185);
        this.setIcon(cannon);
    }
    public void move(Player player){
        if (player.launchStart == true && x > -300){
         x += player.backx;  
        }
        this.setLocation(x,400);
    }
}