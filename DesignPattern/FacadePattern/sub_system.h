#ifndef SUB_SYSTEM_H
#define SUB_SYSTEM_H

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

const std::string c_stateToStrCourier[] = {"�յ�", "��֤�ɴ���", "������Ա", "���Ͱ���", "��ȡ����ȷ��", "���"};
const std::string c_stateToStrVendor[] = { "�յ�", "ȷ�Ͽ��", "�Ӳֿ�õ���Ʒ", "��װ", "��ϵ���Ա", "���" };
const std::string c_stateToStrOrderTeam[] = { "�յ�", "ȷ�ϸ���", "��ϵ��Ӧ��", "���" };
const int c_nMsec = 300;  // ����ʱ�䣨���룩 - Sleep(c_nMsec) �������滻ΪһЩ���õĴ���


//�����Ŷ�
class OrderTeam
{
public:
	void submitRequest()
	{
		m_nState = 0;
	}

	bool checkStatus()
	{
		cout << "�����Ŷ�-��ǰ״̬" << c_stateToStrOrderTeam[m_nState] << endl;

		Sleep(c_nMsec);
		m_nState++;

		return (m_nState == Complete);
	}

private:
    enum States {
        Received,  // �յ�
        VerifyPayment,  // ȷ�ϸ���
        ContactVendor,  // ��ϵ��Ӧ��
        Complete  // ���
    };
    int m_nState;

};


// ��Ӧ��
class Vendor
{
public:
    void submitRequest() {
        m_nState = 0;
    }

    // ���״̬
    bool checkStatus() {
        std::cout << "��Ӧ�� - ��ǰ״̬��" << c_stateToStrVendor[m_nState] << std::endl;

        Sleep(c_nMsec);
        m_nState++;

        return (m_nState == Complete);
    }

private:
    enum States {
        Received,  // �յ�
        VerifyInventory,  // ȷ�Ͽ��
        GetItemFromWareHouse,  // �Ӳֿ�õ���Ʒ
        PackItem,  // ��װ
        ContactCourier,  // ��ϵ���Ա
        Complete  // ���
    };
    int m_nState;
};


// ���Ա
class Courier
{
public:
    // ������ת�������Ա
    void submitRequest() {
        m_nState = 0;
    }

    // ���״̬
    bool checkStatus() {
        std::cout << "���Ա - ��ǰ״̬��" << c_stateToStrCourier[m_nState] << std::endl;

        Sleep(c_nMsec);
        m_nState++;

        return (m_nState == Complete);
    }

private:
    enum States {
        Received,  // �յ�
        VerifyReachbility,  // ��֤�ɴ���
        AssignPerson,  // ������Ա
        DispatchPackage,  // ���Ͱ���
        GetDeliveryConfirmation,  // ��ȡ����ȷ��
        Complete  // ���
    };
    int m_nState;
};






























#endif