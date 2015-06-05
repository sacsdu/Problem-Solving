//http://www.lintcode.com/en/problem/2-sum/
public class Solution {
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1 + 1, index2 + 1] (index1 < index2)
     */
    public int[] twoSum(int[] numbers, int target) {//return index is not the same as return number
        // write your code here
        int first = 0;
        int last = numbers.length - 1;
        int[] result = new int[2];
        result[0] = -1;
        result[1] = -1;
        
        
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < numbers.length; i++){
            if(map.containsKey(target - numbers[i])){
                result[0] = map.get(target - numbers[i]) + 1;
                result[1] = i + 1;
                return result;
            }
            else
                map.put(numbers[i], i);
        }
        
        return result;
        
        
        // Arrays.sort(numbers);
        
        // while(first < last){
        //     int val = numbers[first] + numbers[last];
        //     if(val > target)
        //         last--;
        //     else if(val < target)
        //         first++;
        //     else 
        //         break;
        // }
        
        // int[] result = {first + 1, last + 1};
        // return result;
    }
}
