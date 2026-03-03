#pragma once

class Student {
	private:
		char name[30];
		float mathsGrade;
		float englishGrade;
		float historyGrade;


	public:
		Student();

		void SetName(const char* newName);
		bool SetMathGrade(float grade);
		bool SetEnglishGrade(float grade);
		bool SetHistoryGrade(float grade);

		char* GetName();
		float GetMathGrade();
		float GetEnglishGrade();
		float GetHistoryGrade();

		float GetAverage();
};