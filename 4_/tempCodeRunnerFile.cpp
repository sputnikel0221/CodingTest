    int min = 100;
    for(int i=0;i<N; i++)
    {
        if((visited[B][i]!=0) && min>visited[B][i])
        {
            min = visited[B][i];
        }
    }