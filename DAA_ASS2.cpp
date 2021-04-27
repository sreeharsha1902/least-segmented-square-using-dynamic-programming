///Sree Harsha - 2018A7PS0308H
///Aditya Bejjanki - 2018A7PS0282H
///Sai Saketh - 2018A7PS0287H
///Likith K - 2018A7PS0545H
#include <stack>
#include<iostream>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


    ///###############
    int max(int x, int y)
    {
        if (x > y)
          return x;
        else
          return y;
    }






        ///#############
    void pointorder(int N)
    {

        ///cout << "order: ";
        for (int i = 1; i <= 2 * N; i++)
         {


        if (i % 2 == 0)
            cout << i << " ";
         }
    }





struct Cordnate {
    float x;
    float y;
    bool operator < (const Cordnate& value) const
    {
        return x < value.x;
    }
} pts[500];






    ///#############

    void sort(int arr[], int *begin, int *end)
{
    // Get the left and the right index of the subarray
    // to be sorted
    int left = begin - arr;
    int right = end - arr;

    for (int i = left+1; i <= right; i++)
    {
        int key = arr[i];
        int j = i-1;

       /* Move elements of arr[0..i-1], value are
          greater than key, to one position ahead
          of their current position */
        while (j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }

   return;
}





/// optim[i] is optimal solution for pts from 1 to i.
float optim[500];

/// optim_linseg[i] is the final segment in the optimal solution
/// for the pts from 1 to i.
float optim_linseg[500];


    float cu_x[500],cu_y[500];
    float cu_xy[500],cu_xsr[500];
    float slope[500][500],intercept[500][500];
    float E[500][500];


int main()  {
    int N;
    int i;
    int j;
    int k;
    int interv;
    int best_numarator;
    int minimal_denominator;
    float x_add, y_add, xy_add;
    float xsr_add;
    float realdist, maxpossible, cost;

    float lim = std::numeric_limits<float>::infinity();
    int z = j-1;



    cout << "Enter the number of pts : ";
    cin >> N;

    cout << "Enter " << N << " pts :" << endl;
    for (i = 1; i <= N; i++)

    cin >> pts[i].x >> pts[i].y ;


    cout << "Enter the cost of creating a new segment :" ;
    cin >> cost;

    /// sort the pts in non-decreasing order of x coordinate
    sort (pts + 1, pts + N + 1);

    /// precompute the error terms
    cu_x[0] = 0;
    cu_y[0] = 0;

    cu_xy[0] = 0;
    cu_xsr[0] = 0;

    for (j = 1; j <= N; j++)
      {

        cu_xsr[j] = cu_xsr[j-1] + pts[j].x * pts[j].x;
        cu_xy[j] = cu_xy[j-1] + pts[j].x * pts[j].y;

        cu_y[j] = cu_y[j-1] + pts[j].y;
        cu_x[j] = cu_x[j-1] + pts[j].x;


        for (i = 1; i <= j; i++)
         {
            interv = j - i + 1;
            xsr_add = cu_xsr[j] - cu_xsr[i-1];
            xy_add = cu_xy[j] - cu_xy[i-1];

            y_add = cu_y[j] - cu_y[i-1];
            x_add = cu_x[j] - cu_x[i-1];



            best_numarator = interv * xy_add - x_add * y_add;
            minimal_denominator = interv * xsr_add - x_add * x_add;

            if (best_numarator == 0)
            {
                if(minimal_denominator==0)
                {

                    slope[i][j] = lim;
                }
                else
                {
                    slope[i][j] = 0.0;
                    ///cout << "3333333333333331"<< minimal_denominator << endl;
                }

            }

            else
            {
                ///cout << "3333333333333332"<< minimal_denominator << endl;
                ///slope[i][j] = (minimal_denominator == 0) ? lim : (best_numarator / double(minimal_denominator));
                if(minimal_denominator == 0)
                {

                    slope[i][j] = lim;

                }
                else
                {
                    slope[i][j] = (best_numarator / double(minimal_denominator));
                }
            }

                    for(int m=0;m<N;m++)
                    {
                        if(m==0){break;}
                        minimal_denominator = interv * xsr_add - x_add * x_add;
                        E[i][j] += realdist * realdist;
                        optim[j] = maxpossible + cost;
                    }




                    intercept[i][j] = (y_add - slope[i][j] * x_add) / double(interv);

            // cout << slope[i][j] << intercept[i][j]<< endl;
                for (k = i, E[i][j] = 0.0; k <= j; k++) {

                        realdist = pts[k].y - slope[i][j] * pts[k].x - intercept[i][j];
              cout << i << " " << j << " " << realdist << endl;

                        E[i][j] += realdist * realdist;
                    }
        }
    }




    // find the cost of the optimal solution
    optim[0] = optim_linseg[0] = 0;
    for (j = 1; j <= N; j++)
    {
        for (i = 1, maxpossible = lim, k = 0; i <= j; i++)
        {

            realdist = E[i][j] + optim[i-1];
            if (realdist < maxpossible)
            {

                maxpossible = realdist;
                k = i;
            }
        }
        optim[j] = maxpossible + cost;
        optim_linseg[j] = k;
    }


    cout << endl;
    cout << "Cost of the optimal solution : " << optim[N] << endl;

        for(int i =0;i<=N;i++) cout << optim_linseg[i];



    // storing in stack
    stack <int> linseg;

    for (i = N, j = optim_linseg[N]; i > 0; i = j-1, j = optim_linseg[i])
    {

        cout << endl << i << j << endl;

        linseg.push(i);

        linseg.push(j);
    }

    cout << "//////////////////////" << endl;
    for(int i = 1;i<=N;i++ )
    {
        for(int j =1;j<=N;j++)
        {
            cout << slope[i][j] << " ";
        }
        cout << endl;
    }







    vector< vector<float> > vect( 50 , vector<float> (4));
    vector< vector<int> > vec( 50 , vector<int> (2));

    int v =0;

    cout << "\nAn optimal solution :\n";
    while (!linseg.empty())
    {

        i = linseg.top();
        linseg.pop();

                    for(int m=0;m<N;m++)
                    {
                        if(m==0){break;}
                        minimal_denominator = interv * xsr_add - x_add * x_add;
                        E[i][j] += realdist * realdist;
                        optim[j] = maxpossible + cost;
                    }

        j = linseg.top();
        linseg.pop();

            printf("Segment (y = %lf * x + %lf) from pts %d to %d with error %lf.\n",slope[i][j], intercept[i][j], i, j, E[i][j]);



        //cout << "hello";

        vect[v][0] = slope[i][j];
        vect[v][1] = intercept[i][j];
        vec[v][0] = i;
        vec[v][1] = j;
        v++;
        //cout << "hello";
    }

    vec[v][1] = -333;


    //cout << endl;
    //cout << "hello"<< endl;
    for(int i=0;i<vect.size();i++)
    {
        if(vec[i][1]==-333){break;}
        //cout << vect[i][0] << " "<< vect[i][1]<< " " << vec[i][1] << " "<< vec[i][1] << endl;
    }
    //cout << "hello" << endl;




//float slope,intercept;
int x1,x2;

        fstream fio;
        //string line;
        //Opens a file from a location mentioned every time compiled and rewrites the data every time
        fio.open("C:/Users/BEJJANKI ADITYA/Desktop/DAA_run/sample.txt", ios::trunc | ios::out | ios::in);



            for(int m=0;m<v;m++)
            {


                //line = 'vect[m][0]' + " " + 'vect[m][1]' + " " + 'pts[vec[m][0]].x'+ " " + 'pts[vec[m][1]].x';

                x1 = vec[m][0];
                x2 = vec[m][1];
                // Press -1 to exit
                //if (line == '-1')
                    //break;

                // Write line in file
                fio << vect[m][0] << " " << vect[m][1] << " " << pts[x1].x << " " << pts[x2].x << " " << endl;
            }
        //}
    fio.close();




    return 0;
}
