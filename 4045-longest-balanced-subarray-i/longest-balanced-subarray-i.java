class Solution {
    public int longestBalanced(int[] nums) {
        int n= nums.length;
        int ans=0;
        for(int i=0;i<n;i++){
        HashSet<Integer>ev=new HashSet<Integer>();
        HashSet<Integer>od=new HashSet<Integer>();
            for(int j=i;j<n;j++){
                if((nums[j]&1)>0) od.add(nums[j]);
                else ev.add(nums[j]);
                if(ev.size()==od.size()) ans=Math.max(ans,j-i+1);
            }
        }
        return ans;
    }
}