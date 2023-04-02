package cloudclass.service;
import cloudclass.model.CloudChooseSystem;
import java.util.List;

/**
 * 用户基本信息表 业务层
 *
 *
 */
public interface CloudChooseSystemService {
    /**
     * 所有选课界面基本信息
     *
     * @return 选课界面基本信息
     */
    List<CloudChooseSystem> selectAll();


    CloudChooseSystem selectByCourseId(Long courseId);
}
