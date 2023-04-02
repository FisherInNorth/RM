package cloudclass.mapper;

import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface CloudUserMapper {
    /**
     * 所有云课堂用户基本信息
     *
     * @return 用户基本信息
     */
    List<cloudclass.model.CloudUser> selectAll();


}
