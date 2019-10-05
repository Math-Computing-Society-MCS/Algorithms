int levenshtein(string s1, string s2, int n, int m)
{
    //converting string 1 to string 2
    //String 1 length - n
    //String 2 length - m
	
    if(n==0)
        return m;
    if(m==0)
        return n;
    
    if (s1[n-1] == s2[m-1]) 
        return levenshtein(s1, s2, n-1, m-1);
        
    return min(
                    levenshtein(s1,s2,n,m-1),
                    min(
                        levenshtein(s1,s2,n-1,m),
                        levenshtein(s1,s2,n-1,m-1)
                        )
                    )+1;
}
