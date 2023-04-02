package cloudclass.mapper;

import cloudclass.model.AllClass;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * @author 掘开
 */
@Mapper
public interface AllClassMapper {
    /**
     * 所有课程基本信息
     *
     * @return 课程基本信息
     */
    List<AllClass> selectAllSc();


    /**
     * 查询: 课程ID
     * @param courseId
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
