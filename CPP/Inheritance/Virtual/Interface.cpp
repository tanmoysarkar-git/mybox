#include <iostream>
#include <memory>
namespace projecttype{
    enum type{
        EcoSystem = 0,
        Astronomy };
};

namespace projectStatus{
    enum type{
        Good = 0,
        Average,
        Bad
    };
};
namespace workstatus{
    enum type{
        NotStarted = 0,
        InProgress,
        Done
    };
};
class IProject{
    public:

        virtual void setWorkStatus(const workstatus::type&) = 0;
        virtual void setProjectStatus(const projectStatus::type&) = 0;
        virtual void setProjectType(const projecttype::type&) = 0;
        virtual workstatus::type& getWorkStatus() = 0 ;
        virtual projectStatus::type& getProjectStatus() = 0 ;
        virtual projecttype::type& getProjectType() = 0 ;
        //void test() ; //Not an Interface
};
class Project1:public IProject{
    private:
        projectStatus::type Status;
        projecttype::type Type;
        workstatus::type WorkStatus;
    public:
        Project1()=default;
    
        void setWorkStatus(const workstatus::type&);
        void setProjectStatus(const projectStatus::type&);
        void setProjectType(const projecttype::type&);
        workstatus::type& getWorkStatus() ;
        projectStatus::type& getProjectStatus();
        projecttype::type& getProjectType();
        void test();
        ~ Project1()=default;
};
void Project1::setProjectStatus(const projectStatus::type& _status)
{
    Status=_status;
}
void Project1::setProjectType(const projecttype::type& _type)
{
    Type=_type;
}
void Project1::setWorkStatus(const workstatus::type& _wstatus)
{
    WorkStatus = _wstatus;
}
workstatus::type& Project1::getWorkStatus() {return WorkStatus;}
projectStatus::type& Project1::getProjectStatus()   {return Status;}
projecttype::type& Project1::getProjectType()   {return Type;};

class Project2{
    private: 
        IProject* iproject;
    public:
        Project2()=delete;
        Project2(IProject* _iproject):iproject(_iproject)   {}
        void getgetWorkStatusFromProject1() {std::cout<<"work status: "<<iproject->getWorkStatus()<<std::endl;}
};

class Management:public Project1{
    private:
        std::shared_ptr<IProject> P1;
    public:
        Management(std::shared_ptr<IProject> p1):P1(p1)    {}

};
void SetDataForProject1(std::shared_ptr<IProject> p1)
{
    p1->setProjectStatus(projectStatus::type::Average);
    p1->setProjectType(projecttype::type::EcoSystem);
    p1->setWorkStatus(workstatus::type::InProgress); 
}
int main()
{
    std::shared_ptr<IProject> P1 = std::make_shared<Project1>();
    SetDataForProject1(std::move(P1));
    //same for other project
    //SetDataForProject2(std::move(P2));
    //so on...
    Project1 P11;
    Project2 P2(&P11);
    P2.getgetWorkStatusFromProject1();

    auto P21 = std::make_unique<IProject>();

    std::unique_ptr<Management> MPtr = std::make_unique<Management>(P1);

    

    //std::cout<<"Work status: "<< std::static_cast<std::underlying_type<workstatus>::type>(MPtr->getWorkStatus()) << std::endl;
//A->test(); can't access becasue of Project1 class not of IProject class
return 0;
}