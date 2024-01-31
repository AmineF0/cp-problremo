public class Circle{
  private double x,y, radius;

  public Circle(double x, double y, double radius){
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public Circle(double x, double y, Point p){
    this.x = x;
    this.y = y;
    this.radius = Math.sqrt(Math.pow(x - p.getX(), 2) + Math.pow(y - p.getY(), 2));
  }

  public Circle(Point c, Point p){
    this.x = c.getX();
    this.y = c.getY();
    this.radius = Math.sqrt(Math.pow(this.x - p.getX(), 2) + Math.pow(this.y - p.getY(), 2));
  }

  public Circle(Point y, double radius){
    this.x = y.getX();
    this.y = y.getY();
    this.radius = radius;
  }

  public double getRadius(){
    return radius;
  }
  
  public double getX(){
    return x;
  }

  public double getY(){
    return y;
  }

  public double getArea(){
    return Math.PI * radius * radius;
  }

  public double getPerimeter(){
    return 2 * Math.PI * radius;
  }

  public boolean contains(double x, double y){
    return Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2)) <= radius;
  }

  public boolean containsAll(Point[] tabPoint){
    boolean res = true;
    for(int i = 0; i < tabPoint.length; i++){
      if(!contains(tabPoint[i].getX(), tabPoint[i].getY())){
        res = false;
      }
    }
    return res;
  }
    

  public void setRadius(double radius){
    this.radius = radius;
  }

  public void setX(double x){
    this.x = x;
  }

  public void setY(double y){
    this.y = y;
  }

  public void setCenter(double x, double y){
    this.x = x;
    this.y = y;
  }

  public String toString(){
    return "Cercle(" + x + ", " + y + ","+ radius+")";
  }

}