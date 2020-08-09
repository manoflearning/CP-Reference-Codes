#pragma once
#include <iostream>
#include <io.h>
#include <string>
#include <list>
using namespace std;

string Contents;

void searchingDir(string path, int depth);
int isFileOrDir(_finddata_t fd);
void stringProcess(string s, string path, const int& checkDirFile);

int main() {
	string path = "D:\\0JWK\\0programming\\PS-Reference-Codes\\Reference Codes";
	searchingDir(path, 0);
	cout << Contents << '\n';
}

void searchingDir(string path, int depth) {
	if (depth >= 2) return;

	int checkDirFile = 0;
	string dirPath = path + "\\*.*";
	struct _finddata_t fd;
	intptr_t handle;
	list<_finddata_t> fdlist;

	if ((handle = _findfirst(dirPath.c_str(), &fd)) == -1L) {
		cout << "No file in directory!" << endl;
		return;
	}

	do {
		checkDirFile = isFileOrDir(fd);
		if (fd.name[0] != '.') {
			stringProcess(fd.name, path, checkDirFile);

			if (checkDirFile == 0) searchingDir(path + "\\" + fd.name, depth + 1);
			else fdlist.push_back(fd);
		}

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
}

int isFileOrDir(_finddata_t fd) {
	if (fd.attrib & _A_SUBDIR) return 0;
	else return 1;
}

void stringProcess(string s, string path, const int& checkDirFile) {
	//���� �̸� ���ϱ�
	bool first = true;
	for (int i = 0; i < s.size(); i++) {
		Contents.push_back(s[i]);
		if (first && s[i] == ' ') {
			Contents.push_back('[');
			first = false;
		}
	}
	if (checkDirFile == 1) { //.txt ����
		for (int i = 0; i < 4; i++) Contents.pop_back();
	}
	Contents.push_back(']');

	//�����۸�ũ �ּ� ���ϱ�
	Contents.push_back('(');
	if (checkDirFile == 0) {
		Contents += "https://github.com/manoflearning/PS-Reference-Codes/tree/master/";
	}
	else {
		Contents += "https://github.com/manoflearning/PS-Reference-Codes/blob/master/";
	}
	for (int i = 38; i < path.size(); i++) {
		if (path[i] == ' ') Contents += "%20";
		else {
			if (path[i] == '\\') Contents.push_back('/');
			else Contents.push_back(path[i]);
		}
	}
	Contents.push_back('/');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') Contents += "%20";
		else Contents.push_back(s[i]);
	}
	Contents.push_back(')');
	
	Contents += " <br/>\n";
}

/* ���ͳݿ��� ã�� �ڵ�
#pragma once

#include <iostream> //I/O��Ʈ�� ���
#include <io.h> //���� ����ü ���
#include <string>//��Ʈ�� ��ü ��� ���
#include <list>//����Ʈ �ڷ��� ���
using namespace std;

void searchingDir(string path);
int isFileOrDir(_finddata_t fd);

int main() {

	string path = "C:\\DEV\\test";
	searchingDir(path);

}

void searchingDir(string path)
{
	int checkDirFile = 0;
	string dirPath = path + "\\*.*";
	struct _finddata_t fd;//���丮 �� ���� �� ���� ���� ���� ��ü
	intptr_t handle;
	list<_finddata_t> fdlist;//���丮, ���� ���� ��ü ����Ʈ

	if ((handle = _findfirst(dirPath.c_str(), &fd)) == -1L) //fd ����ü �ʱ�ȭ.
	{
		//�����̳� ���丮�� ���� ���.
		cout << "No file in directory!" << endl;
		return;
	}

	do //���� Ž�� �ݺ� ����
	{
		checkDirFile = isFileOrDir(fd);//���� ��ü ���� Ȯ��(���� or ���丮)
		if (checkDirFile == 0 && fd.name[0] != '.') {
			//���丮�� ���� ����
			cout << "Dir  : " << path << "\\" << fd.name << endl;
			searchingDir(path + "\\" + fd.name);//����� ȣ��
		}
		else if (checkDirFile == 1 && fd.name[0] != '.') {
			//������ ���� ����
			cout << "File : " <<path<<"\\"<< fd.name << endl;
			fdlist.push_back(fd);
		}

	} while (_findnext(handle, &fd) == 0);
	_findclose(handle);
}

int isFileOrDir(_finddata_t fd)
//�������� ���丮���� �Ǻ�
{

	if (fd.attrib & _A_SUBDIR)
		return 0; // ���丮�� 0 ��ȯ
	else
		return 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

}*/