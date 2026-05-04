int hello_recursive(int n) 
{
    if (n <= 1) 
    {
        return 1;
    }
return hello_recursive(n-1) + hello_recursive(n-2);
}
// The time complexity for the code is O(2^n) 
// each call branches into 2 more calls
// the depth is n 