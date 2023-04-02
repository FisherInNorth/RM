package cloudclass.service.impl;
import cloudclass.mapper.CloudUserMapper;
import cloudclass.model.CloudUser;
import cloudclass.service.CloudUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CloudUserServiceImpl implements CloudUserService{
    @Autowired
    private CloudUserMapper mapper;

    /**
     * 查询: 所有用户基本信息
     *
     * @return 用户基本信息
     */
    @Override
    public List<CloudUser> selectAll() {
        return mapper.selectAll();
    }




}
