public class AreaCalculator {

    public static double area(double radius) {

        double areaCircle;
        if(radius < 0) {
            return -1;
        } else {
            areaCircle = radius * radius * Math.PI;
        }
        return areaCircle;
    }

    public static double area(double x, double y) {

        double areaRectangle;
        if((x < 0) || (y < 0)) {
            return -1;
        } else {
            areaRectangle = x * y;
        }
        return areaRectangle;
    }
}
