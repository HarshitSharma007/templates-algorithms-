class Solution
{
    public:
    
    static bool cmp(Item a,Item b){
        double x= double(a.value)/double(a.weight);
        double y=double(b.value)/double(b.weight);
        return x>y;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++){
            if(arr[i].weight<W){
                ans+=arr[i].value;
                W=W-arr[i].weight;
            }
            else {
                
                double y=double(arr[i].value)/double(arr[i].weight);
                ans+=W*(y);
                break;
            }
        }
        
        return ans;
        
    }
        
};
