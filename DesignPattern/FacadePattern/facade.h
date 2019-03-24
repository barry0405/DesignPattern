// facade.h
#ifndef FACADE_H
#define FACADE_H

#include "sub_system.h"

// �������
class OnlineShoppingFacade
{
public:
    OnlineShoppingFacade() {
        m_nCount = 0;
    }

    // ���ظ��ٴ���
    int followupNum() {
        return m_nCount;
    }

    // �ύ����
    void submitRequest() {
        m_nState = 0;
    }

    // ���ٶ���
    bool checkStatus(){
        // �յ���������
        switch (m_nState) {
        case Received:
            m_nState++;
            // ������ת���������Ŷ�
            m_order.submitRequest();
            std::cout << "********** �ύ�������Ŷӣ����ٴ�����" << m_nCount << " **********" << std::endl;
            break;
        case SubmittedToOrderTeam:
            // ��������Ŷ������֤������Ӧ�̷�������
            if (m_order.checkStatus()) {
                m_nState++;
                m_vendor.submitRequest();
                std::cout << "********** �ύ����Ӧ�̣����ٴ�����" << m_nCount << " **********" << std::endl;
            }
            break;
        case SubmittedToVendor:
            // �����Ӧ���ѽ��������������ת�������Ա
            if (m_vendor.checkStatus()) {
                m_nState++;
                m_courier.submitRequest();
                std::cout << "********** �ύ�����Ա�����ٴ�����" << m_nCount << " **********" << std::endl;
            }
            break;
        case SubmittedToCourier:
            // ��������������������
            if (m_courier.checkStatus())
                return true;
        default:
            break;
        }

        m_nCount++;

        // ����δ���
        return false;
    }

private:
    enum States {
        Received,  // �յ�
        SubmittedToOrderTeam,  // �ύ�������Ŷ�
        SubmittedToVendor,  // �ύ����Ӧ��
        SubmittedToCourier  // �ύ�����Ա
    };

    int m_nState;  // ����״̬
    int m_nCount;  // ���ٴ���

    OrderTeam m_order;
    Vendor m_vendor;
    Courier m_courier;
};

#endif // FACADE_H
