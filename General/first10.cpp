#include "../IMPORTME.cpp"



int maxActivitiesICanDo(vector<pair<int,int>>&v)
{
       /*
        you are a very busy man who has very activities in 
        his day try to catch maximam number of activities 
        to do for example if i have activities start time 
        and end time 
        6->9  ||  0->10 || 4->5 || 8->9 || 4->10 || 5->6
        tha maximum number of activities that i can take 
        is 3 = (4->5 , 5->6 , 6->9) if i take any other 
        activity it will overlap with other one
       */

       sort(v.begin(), v.end(), SortPairsAsc);
       int endTime=v[0].second , ans=1;
       for(int i = 1; i<v.size(); i++)
       {
             if(v[i].first>=endTime)
             {
                endTime = v[i].second;
                    ans++;
             }
            
       }
       return ans;
}


signed main()
{
       vector<pair<int, int>> activity = {{1, 10}, {2, 4}, {3, 5}, {2, 6}, {1, 2}, {4, 12}};
       cout << maxActivitiesICanDo(activity);
}