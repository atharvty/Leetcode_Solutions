class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        //making the set {1,2,3,4}
        //and making the factorial
        for(int i = 1; i<n; i++){
            fact = fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        //initialzing the string which will give us the answer
        string ans = "";
        
        //as it's the 0th indexing we are following
        k=k-1;
        
        
        while(true){
            ans = ans + to_string(numbers[k/fact]);  // 16/6=2 which is 3 so 3 _ _ _
            numbers.erase(numbers.begin() + k /fact); //removing 3 from the set {1,2,3,4}
            
            if(numbers.size()==0){
                break;
            }
            k = k % fact; //next value will be 16%6 = 4
            fact = fact/ numbers.size(); //next value will be 6/3 =2 
            
        }
        return ans;
        
    }
};