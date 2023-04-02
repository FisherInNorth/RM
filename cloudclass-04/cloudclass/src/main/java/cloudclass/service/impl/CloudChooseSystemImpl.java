package cloudclass.service.impl;

import cloudclass.mapper.CloudChooseSystemMapper;
import cloudclass.model.CloudChooseSystem;
import cloudclass.service.CloudChooseSystemService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CloudChooseSystemImpl implements CloudChooseSystemService {
    @Autowired
    private CloudChooseSystemMapper mapper;


    @Override
    public List<CloudChooseSystem> selectAll() {
        return mapper.selectAll();
    }


    @Override
    public CloudChooseSystem selectByCourseId(Long courseId) {
        return mapper.selectByCourseId(courseId);
    }


}
