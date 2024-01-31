public class Point {
  private double x, y;
  public Point(double x, double y){
    this.x = x;
    this.y = y;
  }
  public double getX(){
    return x;
  }
  public double getY(){
    return y;
  }
  public void setX(double x){
    this.x = x;
  }
  public void setY(double y){
    this.y = y;
  }
  public double distance(double x, double y){
    return Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2));
  }
  public double distance(Point p){
    return Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
  }
}
