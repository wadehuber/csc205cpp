#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

// O(1) - constant time
int constantTimeMethod(vector<int> nums) {
    return 1;
}

// O(log n) - logarithmic time
int logTimeMethod(vector<int> nums) {
    int counter = 0;
    // Calculate the log (base 2) of the length of the array
    int value = log2(nums.size());
    for(int ii=0;ii<value;ii++) {
        counter++;
    }
    return counter;
}

// O(n) - linear time
int linearTimeMethod(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        counter++;
    }
    return counter;
}

// O(n^2) - quadratic time
int quadraticTimeMethod(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        for (int jj=0;jj<nums.length;jj++) {
            counter++;
        }
    }
    return counter;
}

// O(n^3) - cubic time
public static int cubicTimeMethod(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        for (int jj=0;jj<nums.length;jj++) {
            for (int kk=0;kk<nums.length;kk++) {
                counter++;
            }
        }
    }
    return counter;
}

// O(n log n)
public static int loopMethod1(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        counter += logTimeMethod(nums);
    }
    return counter;
}

// O(n^2 log n)
public static int loopMethod2(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        for (int jj=0;jj<nums.length;jj++) {
            counter += logTimeMethod(nums);
        }
    }
    return counter;
}

// O(3n) = O(n) - linear time
public static int forLoopMethod(Integer[] nums) {
    int counter = 0;
    for(int ii=0;ii<nums.length;ii++) {
        counter++;
    }
    for (int jj=0;jj<nums.length;jj++) {
        counter++;
    }
    for (int kk=0;kk<nums.length;kk++) {
        counter++;
    }
    return counter;
}

public static void main(String[] args) {
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,100);

    vector<int> numbers;
    long int start, end;
    int result;

    cout << "Original array: ";
    for (int ii=0;ii<numbers.length;ii++) {
        numbers.pushBack(dist(mt));
        cout << " " + numbers[ii]);
    }
    cout << endl << endl;
    
    cout << "Results:" << endl;
    /*
    cout << "   Constant time: " << endl;
    start = System.nanoTime();
    result = constantTimeMethod(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
*/
    // Equivalent code in C++:
    // Java version:
    // start = System.nanoTime();
    // result = logTimeMethod(numbers);
    // end = System.nanoTime();
    //cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
    cout << "        Log time: "  << endl;
    const auto start{std::chrono::steady_clock::now()};
    result = logTimeMethod(numbers);
    const auto end{std::chrono::steady_clock::now()};
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;

/*
    cout << "     Linear time: "  << endl;
    start = System.nanoTime();
    result = linearTimeMethod(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
    
    cout << "  Quadratic time: "  << endl;
    start = System.nanoTime();
    result = quadraticTimeMethod(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;

    cout << "      Cubic time: "  << endl;
    start = System.nanoTime();
    result = cubicTimeMethod(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
    
    cout << "   Loop method 1: "  << endl;
    start = System.nanoTime();
    result = loopMethod1(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
    
    cout << "   Loop method 2: "  << endl;
    start = System.nanoTime();
    result = loopMethod2(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
    
    cout << "For Loop method: "  << endl;
    start = System.nanoTime();
    result = forLoopMethod(numbers);
    end = System.nanoTime();
    cout << "iterations=" + result + " (time:" + (end-start) + ")" << endl;
*/    
}
