package cloudclass.service;

import cloudclass.model.AllClass;

import java.util.List;

public interface AllClassCommonService {
    /**
     * 所有课程基本信息
     *
     * @return 课程基本信息
     */
    List<AllClass> selectAllSc();

    /**
     * 查询: 课程ID
     *
     * @param courseId 课程ID
     * @return 课程基本信息
     */
    AllClass selectBycourseIdSc(String courseId);




    /**
     * 查询: 分页查询
     *
     * @param data 查询条件: 课程基本信息
     * @return 课程基本信息
     */
    List<AllClass> selectDataListSc(AllClass data);


    /**
     * 新增
     *
     * @param data 课程基本信息
     * @return 结果
     */
    int insertSc(AllClass data);

    /**
     * 更新
     *
     * @param data 课程基本信息
     * @return 结果
     */
    int updateSc(AllClass data);
}
