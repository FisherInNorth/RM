package cloudclass.controller;

import cloudclass.model.AllClass;
import cloudclass.service.AllClassCommonService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author 掘开
 */
@RestController
@RequestMapping("cloudclass-04/allclass")
@Slf4j
public class AllClassController {
    @Autowired
    private AllClassCommonService allClassCommonService;



    /**
     * 查询所有字段数据
     */
    @GetMapping("list")
    public List<AllClass> list() {
        return allClassCommonService.selectAllSc();
    }

    /**
     * 查询: 课程ID
     */
    @GetMapping(value = "selectByCourseId")
    public AllClass selectBycourseIdSc(String courseId) {
        courseId = "ZXH666";
        return allClassCommonService.selectBycourseIdSc(courseId);
    }

    /**
     * 新增
     *
     * @param data 课程基本信息
     * @return 结果
     */
    @GetMapping(value = "insertTest")
    public int insertSc(AllClass data) {
        data.setSubject("数据结构");
        data.setCourseId("SSTC1314");
        data.setEndtime("week13");
        return allClassCommonService.insertSc(data);
    }

    /**
     * 更新
     *
     * @param courseId 课程基本信息
     * @return 结果
     */
    @GetMapping(value = "/{ClassUpdate}")
    public int updateSc(String courseId) {
        courseId="SSTC115";
        AllClass allClass = allClassCommonService.selectBycourseIdSc(courseId);
        allClass.setCourseNumber("12");

        return allClassCommonService.updateSc(allClass);
    }

/*

     * 查询: 课程ID

@GetMapping(value = "/{courseId}")
public AllClass selectBycourseIdSc(@PathVariable String courseId) {
    return allClassCommonService.selectBycourseIdSc(courseId);

      新增
      @GetMapping(value = "/{Class}")
    public int insertSc(@PathVariable AllClass data) {
        return allClassCommonService.insertSc(data);
    }

    更新
    @GetMapping(value = "/{Classupdate}")
    public int updateSc(@PathVariable AllClass data) {
        return allClassCommonService.updateSc(data);
    }
 */

}
