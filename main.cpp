#include <iostream>
#include <vector>
using namespace std;

class DuplicationResolver{
    public :
        void resolveDuplication(std::vector<int>& list , int step){
            if (step == 0){
                list = {list[0]};
                return;
            }
            int numberOfDuplicates = getNumberOfDuplicate(list , step);
            while(numberOfDuplicates > 0){
                int duplicatedIndex = getDuplicatedIndex(list ,  step);
                list.erase(list.begin() + duplicatedIndex);
                numberOfDuplicates -- ;
            }
        }

    private :
        int getNumberOfDuplicate(std::vector<int>& list , int step){
            int actualLength  = list.size();
            int firstValue = list[0];
            int lastValue = list[actualLength- 1];
            int expectedLength = ((lastValue - firstValue)/step) + 1 ;
            return actualLength - expectedLength;
        }

        int getDuplicatedIndex(std::vector<int>& list , int step){
            int expectedValue ;
            int first = 0 ;
            int last = list.size();
            int middle ;

            int firstValue = list[0];
            //binary search for finding duplicates
            while(first <= last){
                middle = (first + last) / 2;
                expectedValue = firstValue + step *middle ;
                // expected = xo + delta X * step
                if (expectedValue ==list[middle]){
                    first = middle + 1 ;
                }else {
                   last = middle-1 ;
                }
            }
            return middle;
        }
};

int main()
{
    DuplicationResolver d ;
    std::vector<std::vector<int>> testValues = {
                                                {-3,-1,1,1,3},
                                                {-10,-7,-4,-1,2,2,5},
                                                {-1,0,0,0,0,0},
                                                {0,0,0,0,0,0},
                                                {-1,-1,-1,-1,-1,-1},

                                                {-3,-2,-1,0,0},
                                                {4,4,7,7,10,10,13,16},
                                                {1,2,3},
                                                {100,200,300,300,300,400,400,400},
                                                {11,14,17,20,23},

                                                {12,16,20,24,24},
                                                {11,11,17,23,23},
                                                {11,17,23,23,29},
                                                {11,17,23,29,29},
                                                {11,17,17,23,29},
                                                };

    std::vector<int> steps =  {2,3,1,0,0,  1,3,1,100,3,  4,6,6,6,6};

    for (int listIndex= 0 ; listIndex < testValues.size() ; listIndex++  ){
        d.resolveDuplication(testValues[listIndex], steps[listIndex]) ;
        for (int i = 0 ; i < testValues[listIndex].size(); i ++){
            cout<<testValues[listIndex][i]<<", ";
        }
        cout<<endl;
    }
    return 0;
}
