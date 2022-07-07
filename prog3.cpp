// #include<fstream>
// #include<iostream>
//  #include<bits/stdc++.h>
// using namespace std;
// class student{
//     private:char name[4],sem[10],buff[45],branch[10],extra[45];
//     public:void read()
//         {
//             cout<<"Enter the name sem &branch"<<endl;
//             cin>>name>>sem>>branch;
//         }

//     void pack(fstream &ofile)
//     {
//             read();
//         strcpy(buff,"");
//         strcat(buff,name);
//         strcat(buff,"|");
//         strcat(buff,sem);
//         strcat(buff,"|");
//         strcat(buff,branch);
//         strcat(buff,"|");
//         strcat(buff,"\n");
//         ofile.write(buff,strlen(buff));
//     }

//      void unpack(fstream &ifile)
//     {
//     	while(!ifile.eof())
//     	{
//     	ifile.getline(name,20,'|');
//     	ifile.getline(sem,10,'|');
//     	ifile.getline(branch,10,'|');
//     	ifile.getline(extra,45,'\n');
//     	cout<<name<<" "<<sem<<" "<<branch<<endl;
    	 
//     	}
//     }

//     int main()
//     {
//         student s1;
//         fstream f1,f2,f3;
//         f1.open("b.txt",ios::out | ios::app);
//         s1.pack(f1);
//         f2.open("b.txt",ios::in);
//         s1.pack(f2);
//         return 0;
//     }
// };


  #include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;
class Student
{
    private : char name[20],sem[10],branch[10],buff[45],extra[45];
    public : void read()
    {
        cout<<"Enter the Name\n";
        cin>>name;
        cout<<"Enter Semester\n";
        cin>>sem;
        cout<<"Enter the Branch\n";
        cin>>branch;
    }

    void pack(fstream &ofile)
    {
        int input;
        cout<<"Enter the number of students\n";
        cin>>input;
        for(int i=0;i<input;i++)
        {
            read();
        strcpy(buff,"");
        strcat(buff,name);
        strcat(buff,"|");
        strcat(buff,sem);
        strcat(buff,"|");
        strcat(buff,branch);
        strcat(buff,"|");
        strcat(buff,"\n");
        ofile.write(buff,strlen(buff));
        }
        
    }
    void unpack(fstream &ifile)
    {
    	while(!ifile.eof())
    	{
    	ifile.getline(name,20,'|');
    	ifile.getline(sem,10,'|');
    	ifile.getline(branch,10,'|');
    	ifile.getline(extra,45,'\n');
    	cout<<name<<" "<<sem<<" "<<branch<<endl;
    	 
    	}
    }

int search(fstream &ifile,char key[45])
{
    char extra[45];
    while(!ifile.eof())
    {
        ifile.getline(name,20,'|');
        ifile.getline(sem,10,'|');
        ifile.getline(branch,10,'|');
        ifile.getline(extra,45,'\n');
        
        if(strcmp(name,key)==0)
        {
            cout<<"Record found\n";
            cout<<name<<" "<<sem<<" "<<branch<<"\n";
            return 1;
        }

    }
    
    return 0;
}
 void modify(fstream &ifile,char key[20])
    {
      Student s1[5];
       int i=0,flag=0,n;
    	while(!ifile.eof())
    {
        ifile.getline(s1[i].name,20,'|');
        ifile.getline(s1[i].sem,10,'|');
        ifile.getline(s1[i].branch,10,'|');
        ifile.getline(s1[i].extra,45,'\n');
        i++;
    }
    for(int j=0;j<i;j++)
    {
       if(strcmp(s1[i].name,key)==0)
        {
            flag=1;
            cout<<"record found enter the modification\n";
            cout<<"Enter the name";
            cin>>s1[j].name;
            cout<<"Enter the sem";
            cin>>s1[i].sem;
            cout<<"Enter the branch";
            cin>>s1[i].branch;
        }
    }
    if(flag==0)
    {
        cout<<"record not found";
    }
    else
    ifile.open("c.txt",ios::trunc|ios::app);
    for(int i=0;i<n;i++)
    {
        strcat(buff,s1[i].name);
        strcat(buff,"|");
        strcat(buff,s1[i].sem);
        strcat(buff,"|");
        strcat(buff,s1[i].branch);
        strcat(buff,"|");
        strcat(buff,"\n");
        ifile.write(buff,strlen(buff));
    }
    }

};

int main()
{
    fstream ofile,ifile,iofile;
    string filename;
    char key[20];
    Student st,st1[4];
    cout<<"Enter the filename\n";
    cin>>filename;
    int ch;
    while(1)
    {
    cout<<"Enter your choice :\n1)pack\n2)unpack\n3)search\n4)modify\n5)exit\n";
    cin>>ch;
    switch(ch)
    {
    	case 1:ofile.open(filename,ios::out | ios::app);
   		 st.pack(ofile);
   		 ofile.close();
   		 break;
   	case 2: ifile.open(filename,ios::in);
    		st.unpack(ifile);
    		ifile.close();
    		break;
    case 3:
            // cout<<st.search(ifile);
            cout<<"Enter the search record";
            cin>>key;
            ifile.open(filename,ios::in|ios::out);
            if(st.search(ifile,key)==0)
            {
                cout<<"record not found"<<endl;
            }
                ifile.close();
                break;
            
    case 4:iofile.open(filename,ios::in|ios::out);
    		cout<<"Enter name to modify\t";
    		cin>>key;
    		st.modify(iofile,key);
    		iofile.close();
    	break;
   	case 5:exit(0);
    	break;
   	
    
    }
    
    }
  
   return 0;
    
}


