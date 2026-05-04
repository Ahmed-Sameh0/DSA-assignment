void test(int n) 
{
    int i = n;
    while (i > 1) // O(log n) i is divided by 2 each iteration
    {
        int j = 1;
        while (j < i) // O(log i) j is doubled until it reaches i
        {
            j *= 2; 
        }
        i /= 2;
    }
}
// The time complexity for the code is O( (log n)^2 )