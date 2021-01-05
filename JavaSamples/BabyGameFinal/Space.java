import java.awt.*;
import javax.swing.*;
public class Space extends JLabel{
    private int rx;
    private int ry;
    private boolean bar, barUp, barDown;
    public Space (){
        rx = 250;
        ry = 601;
    }
    public void draw(Graphics page){
        page.setColor(Color.ORANGE);
        page.fillRect(250,600,500,50);
        page.setColor(Color.RED);
        page.fillRect(rx,ry,10,48);
    }
    public void move(){
        if(bar = true && rx < 750 && barUp == true){
            rx+=10;
            if(rx == 750){
                barUp = false;
                barDown = true;
            }
        }
        if(bar = true && rx > 250 && barDown == true){
            rx-=10;
            if(rx == 250){
                barUp = true;
                barDown = false;
            }
        }
        this.setLocation(rx,ry);
    }
    }