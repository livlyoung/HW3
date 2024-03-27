//PaintDryTimerStarter.cpp
//Homework 3 part 2
//Liv Young


#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;




struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};


long long int get_time_remaining(DryingSnapShot dss){
	long long int  timeRemaining = dss.timeToDry->GetTimeCodeAsSeconds() - (time(0) - dss.startTime);
	return timeRemaining;
}


string drying_snap_shot_to_string(DryingSnapShot dss){
	// Replace with your code
	string s;
	s.append(dss.name);
	s.append(" (takes ");
	s.append(dss.timeToDry->ToString());
	s.append(" to dry)");
	s.append(" time remaining: ");
	TimeCode remaining(0,0,get_time_remaining(dss));
	s.append(remaining.ToString());

	return s;
}


double get_sphere_sa(double rad){
	double surfaceArea = 4*M_PI*(rad*rad);
	return surfaceArea;
}


TimeCode *compute_time_code(double surfaceArea){

	TimeCode *tc = new TimeCode(0, 0, surfaceArea);

	return tc;
}


void tests(){
	// get_time_remaining
	DryingSnapShot dss;
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	long long int ans = get_time_remaining(dss);
	assert(ans > 6 && ans < 8);

	DryingSnapShot dss2;
	dss2.startTime = time(0);
	TimeCode tc2 = TimeCode(0, 0, 50);
	dss2.timeToDry = &tc2;
	long long int ans2 = get_time_remaining(dss2);
	assert(ans2 > 49 && ans2 < 51);



	// get_sphere_sa
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);

	double sa2 = get_sphere_sa(1.0);
	assert (12.5663< sa2 && sa2 < 12.5664);

	double sa3 = get_sphere_sa(0.75);
	assert (7.06858 < sa3 && sa3 < 7.06859);


	// compute_time_code
	TimeCode *tc3 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc3->GetTimeCodeAsSeconds() == 1);
	delete tc3;


	TimeCode *tc4 = compute_time_code(60.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc4->GetTimeCodeAsSeconds() == 60);
	delete tc4;


	cout << "ALL TESTS PASSED!" << endl;

}


int main(){

	
	char userIn;
	cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
	cin>>userIn;
	vector<DryingSnapShot> v{};
	
	while(userIn != 'Q' && userIn != 'q'){
		if(userIn == 'A' || userIn == 'a'){
			DryingSnapShot ds;
			time_t start = time(0);	
			double inRad;
			cout<<"Radius:";
			cin>>inRad;
			int randNum = rand();
			string batchID = to_string(randNum);
			ds.name = "Batch-"+batchID;
			ds.startTime = start;
			unsigned int surfaceArea = get_sphere_sa(inRad);
			ds.timeToDry = compute_time_code(surfaceArea);
			v.push_back(ds);

			cout<<ds.name<< " will dry in: " <<ds.timeToDry->ToString()<<endl;

			cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
			cin>>userIn;


		}else if(userIn == 'V' || userIn == 'v'){
			

			if(v.size() == 0){ //check if v is empty
				cout<<"Everything is dry!"<<endl;
				cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
				cin>>userIn;
			}

			for(size_t i = 0; i < v.size(); i++){
				unsigned long long int timeRemainingUnsigned = get_time_remaining(v.at(i)); 
				if(timeRemainingUnsigned > v.at(i).timeToDry->GetTimeCodeAsSeconds())
				{
					delete v.at(i).timeToDry;
					v.erase(v.begin()+i);
					if(i == v.size()){
						i -=1;
					}
			 	}

				if(v.size() == 0){ //check if v is empty
					cout<<"Everything is dry!"<<endl;
					cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
					cin>>userIn;
				}else{
					cout<<drying_snap_shot_to_string(v.at(i))<<endl;
					
				}

				
			}
			
			if(v.size() != 0){
				cout<< v.size() << " items being tracked"<<endl;
			}

			cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
			cin>>userIn;

		}else{
			cout<<"Invalid Input!"<<endl;
			cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit:";
			cin>>userIn;

		}
	}


	tests();
	return 0;
}