#include "tensor.h"

#include <iostream>

bool Tensor::ReadFeatures(std::istream& stream, mnist::Classifier::features_t& features) 
{
     std::string line;
     std::getline(stream, line);

     features.clear();
     std::istringstream linestream{line};
     double value;

     while (true) 
     {
          linestream.get(); // read ','
          linestream >> value;
          if(!linestream) break;
	//	  std::cout << "red value:" << value << std::endl;
          features.push_back(value);
     }
     return stream.good();
}

Tensor::Tensor(const char* model, const char* test_file, int width, int height)
{
	auto clf = mnist::TfClassifier{model, width, height};
	auto features = mnist::TfClassifier::features_t{};
	std::ifstream test_data{test_file};
	
	if(!test_data) result = 0;

	float right_answer = 0;
	float all_answer = 0;
	for(;; ++all_answer) 
	{
		size_t y_true;
		test_data >> y_true;

		if(!ReadFeatures(test_data, features)) 
			break;
		auto y_pred = clf.predict(features);
		
		if(y_true == y_pred) ++right_answer;
	}
    result = right_answer / all_answer;
}