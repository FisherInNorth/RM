package cloudclass.service.impl;

import cloudclass.mapper.AllClassMapper;
import cloudclass.model.AllClass;
import cloudclass.service.AllClassCommonService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author 掘开
 */
@Service
public class AllClassCommonServiceImpl implements AllClassCommonService {
    @Autowired
    private AllClassMapper mapper;


    @Override
    public List<AllClass> selectAllSc() {
        return mapper.selectAllSc();
    }

    @Override
    public AllClass selectBycourseIdSc(String courseId) {
        return mapper.selectBycourseIdSc(courseId);
    }

    @Override
    public List<AllClass> selectDataListSc(AllClass data) {
        return mapper.selectDataListSc(data);
    }


    /**
     * 新增
     *
     * @param data 课程基本信息
     * @return 结果
     */
    @Override
    public int insertSc(AllClass data) {
        int row = mapper.insertSc(data);
        return row;
    }

    /**
     * 更新
     *
     * @param data 课程基本信息
     * @return 结果
     */
    @Override
    public int updateSc(AllClass data) {
        int row = mapper.updateSc(data);
        return row;
    }
}