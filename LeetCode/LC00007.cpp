class Solution {
public:
    int reverse(int x) {
        int arr[33];
        int flag = 0, count = 0, s;
        int lock = 1;
        s = x;
        while(s)
        {
            arr[flag++] = s % 10;
            if(lock && s%10 == 0 )
                count++;
            else
                lock = 0;
            s /= 10;
        }
        int sign;
        if(x >= 0)
            sign = 1;
        else
            sign = -1;
        int verifier[10]{2,1,4,7,4,8,3,6,4,9};
        if(flag == 10)
            for(int i = 0; i < 10; i++)
                if(sign * arr[i] > verifier[i])
                    return 0;
                else if(arr[i] == verifier[i] * sign)
                    continue;
                else
                    break;
        int t = 1;
        int ans = 0;
        for(int i = flag-1; i >= count; i--)
        {
            ans += arr[i] * t;
            t *= 10;
        }
        return ans;
    }
};