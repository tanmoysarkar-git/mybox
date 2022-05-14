/**
 * @brief coupling header classes
 * 
 */
#ifndef __GENERATE_OUTPUT_H__
#define __GENERATE_OUTPUT_H__

class IOutputGenerator{
    public:
        virtual void generateOutput() = 0;
};

class CSVOutputGenerator: public IOutputGenerator{
    public:
        void generateOutput() override
        {
            std::cout<<"CSV output generated"<<std::endl;
        }
};

class JSONOutputGenerator: public IOutputGenerator{
    public:
        void generateOutput() override
        {
            std::cout<<"JSON output generated"<<std::endl;
        }
};
#endif