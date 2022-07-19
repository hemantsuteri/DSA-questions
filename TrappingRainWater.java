class Solution {
    public int trap(int[] height) {
        int water = 0;
        int size = height.length;
        int l[] = new int[size];
        int r[] = new int[size];
        int left = height[0];
        int right = height[size-1];
        int i;
        for(i=0; i<size; i++){
            if (height[i] > left){
                left = height[i];
            }
            l[i] = left;
        }
        for(i=size-1; i>=0; i--){
            if (height[i] > right){
                right = height[i];
            }
            r[i] = right;
        }
        for(i = 0; i<size; i++){
            int area = Math.min(l[i], r[i]) - height[i];
            water += area;
        }
        return water;
    }
}
