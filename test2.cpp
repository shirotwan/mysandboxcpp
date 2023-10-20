#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <process.h>
#define NOMINMAX // More secure

using namespace std;

int main(int argc, char ** argv)
{
 STARTUPINFO SI;
 PROCESS_INFORMATION PI;
 memset(&SI,0,sizeof(SI));
 memset(&PI,0,sizeof(PI));
 SI.cb = sizeof(SI);

 //ProcessorCap
 if(!CreateProcess(NULL,"Notepad.exe",NULL,NULL,false,0,NULL,NULL,&SI,&PI))
 {
  printf("Error %lu",GetLastError());
  return 1;
 }
 DWORD ExitCode;
 do
 {
  GetExitCodeProcess(PI.hProcess,&ExitCode);
  Sleep(100);
 }while (ExitCode == STILL_ACTIVE);
 printf("Exited");
}