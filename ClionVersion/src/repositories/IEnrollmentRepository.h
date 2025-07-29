//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_IENROLLMENTREPOSITORY_H
#define CLIONVERSION_IENROLLMENTREPOSITORY_H
#include "../models/EnrollmentRecord.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <unordered_map>


class EnollmentRepositotyError : public std::runtime_error {
public:
    EnollmentRepositotyError(const std::string& s) : std::runtime_error(s){}
};

class IEnollmentRepository{
public:
    virtual ~IEnollmentRepository() = default;

    // --- Required Methods (The Contract) ---

    // ����һ���µĵǼ���Ϣ
    virtual void addEnrollment(const EnrollmentRecord& e) = 0;

    // ɾ��һ���Ǽ���Ϣ
    virtual void deleteEnrollment(const std::string& sid, const std::string& cid) = 0;

    // ��ȡѡ��ָ���γ̵�����ѧ��
    virtual std::vector<std::string> getAllStudentsForACourse(const std::string& cid) = 0;

    // ��ȡָ��ѧ��ѡ������пγ�
    virtual std::vector<std::string> getAllCoursesForAStudent(const std::string& sid) = 0;

    // ��ȡĳ��ѧ��ĳ�ſεĳɼ�
    virtual int getGrade(const std::string& sid, const std::string& cid) = 0;

    // ��ȡָ��ѧ�����пγ̵ĳɼ�,key:courseID, value: grade
    virtual std::vector<EnrollmentRecord>
    getGradesForAStudent(const std::string& sid) = 0;

    // ��ȡָ���γ�����ѧ���ĳɼ�
    virtual std::vector<EnrollmentRecord>
    getGradesForACourse(const std::string& cid) = 0;

    // ����ĳ��ѧ��ĳ�ſεĳɼ�
    virtual void assignGrade(const std::string& sid, const std::string& cid, int grade) = 0;

    virtual bool containsEnrollment(const std::string& sid, const std::string& cid) = 0;

};
#endif //CLIONVERSION_IENROLLMENTREPOSITORY_H
