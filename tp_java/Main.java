import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Circle c1 = new Circle(new Point(2, 2), new Point(5, 6));
    System.out.println("Aire du cercle: " + c1.getArea());
  }

  public boolean containsAll(Circle c, Point[] tabPoint){
    boolean res = true;
    for(int i = 0; i < tabPoint.length; i++){
      if(!c.contains(tabPoint[i].getX(), tabPoint[i].getY())){
        res = false;
      }
    }
    return res;
  }
  
}