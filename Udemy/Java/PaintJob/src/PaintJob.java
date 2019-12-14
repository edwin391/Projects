public class PaintJob {
    public static int getBucketCount(double width, double height, double areaPerBucket, int extraBuckets) {
        int bucketsNeeded = 0;
        double area = 0;
        double paintOwned;
        double temp = 0;

        if(width <= 0 || height <= 0 || areaPerBucket <= 0 || extraBuckets < 0) {
            bucketsNeeded = -1;
        } else {
            area = width * height;
            paintOwned = areaPerBucket * extraBuckets;
            if (paintOwned < area) {
                temp = area - paintOwned;
                temp = temp / areaPerBucket;
            }
            //System.out.println(temp);
            long temp2 = Math.round(temp);
            bucketsNeeded = (int)temp2;
        }

        return bucketsNeeded;
    }
}
