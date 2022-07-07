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
        while(strlen(buff)<45)
        {
            strcat(buff,"!");
        }
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
 void modify(fstream &iofile,char key[20])
    {
    	if(search(iofile,key))
    	{
    		cout<<"Enter modification details\n"<<endl;
    		iofile.seekp(-46,ios::cur);
    		pack(iofile);
    	}
    	else
    	{
    		cout<<"****Record not found****\n";
    	}
    }
};

int main()
{
    fstream ofile,ifile,iofile;
    string filename;
    char key[20];
    Student st;
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
    case 3:ifile.open(filename,ios::in|ios::out);
            // cout<<st.search(ifile);
            cout<<"Enter the search record";
            cin>>key;
            if(st.search(ifile,key)==0)
                cout<<"record not found"<<endl;
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


