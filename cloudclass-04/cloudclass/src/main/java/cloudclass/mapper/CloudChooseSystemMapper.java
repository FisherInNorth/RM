package cloudclass.mapper;
import cloudclass.model.CloudChooseSystem;
import org.apache.ibatis.annotations.Mapper;
import java.util.List;

/**
 * @author 掘开
 */
@Mapper
public interface CloudChooseSystemMapper {
    /**
     * 所有云课堂选课界面基本信息
     *
     * @return 选课界面基本信息
     */
    List<CloudChooseSystem> selectAll();

    CloudChooseSystem selectByCourseId(Long courseId);

}