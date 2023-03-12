#include "tf_classifier.h"

#include <sstream>
#include <fstream>

class Tensor
{
private:
    bool ReadFeatures(std::istream& stream, mnist::Classifier::features_t& features);
public:
    Tensor(const char* model, const char* test_file, int width, int height);
    float result;
};

