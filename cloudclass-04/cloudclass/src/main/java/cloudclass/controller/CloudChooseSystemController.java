package cloudclass.controller;

import cloudclass.model.CloudChooseSystem;
import cloudclass.service.CloudChooseSystemService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author 掘开
 */
@RestController
@RequestMapping("cloudclass-04/system")
@Slf4j
public class CloudChooseSystemController {
    @Autowired
    private CloudChooseSystemService cloudChooseSystemService;

    @GetMapping("list")
    public List<CloudChooseSystem> list() {

        List<CloudChooseSystem> list = cloudChooseSystemService.selectAll();
        return list;
    }

    @GetMapping(value = "/{courseId}")
    public CloudChooseSystem selectByCourseId(@PathVariable Long courseId) {
        return cloudChooseSystemService.selectByCourseId(courseId);
    }
}
