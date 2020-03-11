//
//  TrainNetWorkConfiguration.m
//  SOHUEhr
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年  . All rights reserved.
//

#import "TrainNetWorkConfiguration.h"

@implementation TrainNetWorkConfiguration

static TrainNetWorkConfiguration *defaultConfiguration = nil;


+ (TrainNetWorkConfiguration *)defaultConfiguration
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
    
        defaultConfiguration = [[TrainNetWorkConfiguration alloc] initWithHostString:@""];
    });
    return defaultConfiguration;
}

- (TrainNetWorkConfiguration *)initWithHostString:(NSString *)hostString{
    self = [super init];
    if (self)
    {
        _hostString = hostString;
    }
    
    return self;
 
}


+(NSString *)trainGetAppUpdate{
    return @"/app/user/getUpdate.action";
}

/**
 *  登陆
 */

+(NSString *)trainLogin{
    
    return @"/app/user/loginApp.action";

}

/**
 *  欢迎页
 */

+(NSString *)trainGetWelcomeAd{
    
    return @"/app/user/getStartPage.action";
    
}

#pragma   mark - 首页

+(NSString *)trainMain{
//    return @"/app/user/login.action";
    return @"/app/user/homePage.action";

}



+(NSString *)trainWebView{
//    return @"/ilearn/common/pages/validate.jsp";
    return @"/learn/common/pages/validate.jsp";
//    return @"/kindee/common/pages/validate.jsp";
}
+(NSString *)trainWebDocIsAppraise{
    return @"/app/user/docIsappraise.action";
}

/**
 *  首页九宫格信息 (类似主题)
 */

+(NSString *)trainmainCollection{
    return @"/app/user/getFns.action";
}

#pragma mark - 报名
+(NSString *)trainGetRegistList{
    return @"/app/user/regist.action";
}


#pragma   mark - 个人中心

+(NSString *)trainGetUserCenter{
    return @"/app/user/center.action";
}

+(NSString *)trainGetUserCenterCourse{
    return @"/app/user/centerCourse.action";
}
+(NSString *)trainGetUserCenterTopic{
    return @"/app/user/centerTopic.action";
}
+(NSString *)trainGetUserCenterGroup{
    return @"/app/user/centerGroup.action";
}





#pragma   mark - 搜索
+(NSString *)trainSearch{
    return @"/app/user/mobileSearch.action";
}

/**
 *  文档标签list
 */
+(NSString *)trainSearchTags{
    return @"/app/user/getLabels.action";
}
/**
 *  圈子标签list
 */
+(NSString *)trainTopicTags{
    return @"/app/user/getTopicTagList.action";
}

#pragma   mark - 课程

+(NSString *)trainCourse{
    return @"/app/user/getCourseList.action";
}

+(NSString *)trainMyCourse{
    return @"/app/user/getMyCourseList.action";
}

/**
 *  课程分类 list
 */
+(NSString *)trainCourseCategoryList{
    return  @"/app/user/getCourseCategoryLst.action";
}

/**
 * 课程简介
 */
+(NSString *)trainCourseInfo{
    return @"/app/user/getCourseInfo.action";
}
/**
 * 课程目录
 */
+(NSString *)trainCourseHourInfo{
    return @"/app/user/getHourList.action";
}

/**
 * 课程笔记
 */
+(NSString *)trainCourseNote{
    return @"/app/user/notes.action";
}

/**
 * 课程笔记
 */
+(NSString *)trainCourseClassNote{
    return @"/app/user/getClassCourseNote.action";
}


/**
 * 课程讨论
 */
+(NSString *)trainCourseDiscuss{
    return @"/app/user/discussion.action";
//    return @"/app/user/newDiscussion.action";
}

/**
 * 课程评价
 */
+(NSString *)trainCourseAppraiseList{
    return @"/app/user/findCommentLst.action";
//    return @"/app/user/newFindCommentLst.action";
}

/**
 * 获取目录 / 视频 的播放URL
 */
+(NSString *)trainCourseHourURL{
    return @"/app/user/getPlayLink.action";
}



/**
 *  获取课程报名状态
 */
+(NSString *)trainGetCourseRegisterStatus{
    return @"/app/user/isRegi.action";
}

/**
 *  课程报名
 */
+(NSString *)trainCourseRegister{
    return @"/app/user/signUpCourse.action";
}


/**
 * 课程  添加笔记
 */
+(NSString *)trainCourseAddNote{
    return @"/app/user/addNotes.action";
}

/**
 * 项目课程  添加笔记
 */
+(NSString *)trainClassCourseAddNote{
    return @"/app/user/addClassCourseNote.action";
}

/**
 * 课程  编辑笔记
 */
+(NSString *)trainCourseEditNote{
    return @"/app/user/editNotes.action";
}

/**
 * 课程  添加评价
 */
+(NSString *)trainCourseAddAppraise{
    return @"/app/user/addComment.action";
}
/**
 * 项目课程  添加评价
 */
+(NSString *)trainClassCourseAddAppraise{
    return @"/app/user/addClassCourseComment.action";
}

/**
 * 课程  删除评价
 */
+(NSString *)trainCourseDeleteAppraise{
    return @"/app/user/delComment.action";
}



/**
 * 项目课程  删除评价
 */
+(NSString *)trainClassCourseDeleteAppraise{
    return @"/app/user/delClassComment.action";
}

/**
 * 课程  更新课时文档状态
 */
+(NSString *)trainCourseUpdateHourWithDoc{
    return @"/app/user/saveMobileCourseDoc.action";
}

/**
 * 课程  更新课时 考试状态
 */
+(NSString *)trainCourseUpdateHourWithExam{
    return @"/app/user/saveMobileCourseExam.action";
}
/**
 * 课程  更新课时 考试状态
 */
+(NSString *)trainGetHourStatusWithExam{
    return @"/app/user/getHourStatus.action";
}

/**
 * 课程  更新课时学习时间
 */
+(NSString *)trainCourseUpdateStudyTime{
    return @"/app/user/addLh.action";
}
/**
 * 项目课程  更新项目课程课时学习时间
 */
+(NSString *)trainClassUpdateStudyTime{
    return @"/app/user/saveVideoStudyRecordByClass.action";
}
/**
 更新离线学习记录
 */
+(NSString *)trainUpdateLocalStudyTime {
    
    return @"/app/user/addOffLine.action";
}

#pragma   mark - 项目

+(NSString *)trainClass{
    return @"/app/user/getClassList.action";
}


/**
 * 项目 成绩策略
 */
+(NSString *)trainClassGradeInfo{
    return @"/app/user/getClassTactic.action";
}

/**
 * 获取项目阶段
 */
+(NSString *)trainClassPhaseInfo{
    return @"/app/user/getClassJdList.action";
}

/**
 * 获取阶段资源
 */
+(NSString *)trainClassPhaseRes{
    return @"/app/user/getClassJdRes.action";
}

/**
 * 获取阶段课时
 */
+(NSString *)trainClassPhaseHourList{
    return @"/app/user/getHourList.action";
}


/**
 * 项目评论列表
 */
+(NSString *)trainClassCommendList{
    return @"/app/user/getClassComment.action";
}

/**
 * 添加项目评价
 */
+(NSString *)trainAddClassCommend{
    return @"/app/user/addClassComment.action";
}


/**
 * 项目 详情 更多学员
 */
+(NSString *)trainClassAllMates{
    return @"/app/user/getClassStudents.action";
}
/**
 * 项目 收藏
 */
+(NSString *)trainClassCollect{
    return @"/app/user/classFav.action";
}


/**
 * 项目 课程list
 */
+(NSString *)trainClassCourseList{
    
//    return @"/app/user/getClassCourse.action";
    return @"/app/user/getClassCourseList.action";
}
/**
 * 项目 详情 (概览 , 讲师 list ,学员list )
 */
+(NSString *)trainClassDetail{
    return @"/app/user/getClassInfo.action";
}
/**
 * 项目 调查 评估 考试
 */
+(NSString *)trainClassExamList{
    return @"/app/user/getClassExamSvEv.action";
}


+(NSString *)trainMyClass{
    return @"/app/user/myClass.action";
//    return @"/app/user/getMyClass.action";
}

+(NSString *)trainMyClassNotRegister{
    return @"/app/user/getClassList.action";
    //    return @"/app/user/getMyClass.action";
}

/**
 * 项目 报名
 */
+(NSString *)trainClassRegister{
    return @"/app/user/signUpClass.action";
}

/**
 * 项目 退出报名
 */
+(NSString *)trainClassUnRegister{
    return @"/app/user/dropOutClass.action";
}

/**
 * 项目 签到
 */
+(NSString *)trainClassSignIn{
    return @"/app/user/signInClass.action";
}

/**
 * 项目 详情 更多学员
 */
+(NSString *)trainClassMorePerson{
    return @"/app/user/getClassPersonList.action";
}

/**
 * 项目 详情 更多讲师
 */
+(NSString *)trainClassMoreLecturer{
    return @"/app/user/getClassLecturerList.action";
}

/**
 * 项目 详情 更多评价  (暂未实现)
 */
+(NSString *)trainMoreApparise{
    return @"/app/user/getClassLecturerList.action";
}

#pragma   mark - 圈子  话题

+(NSString *)trainGroup{
    return @"/app/user/getGroupList.action";
}

+(NSString *)trainMyGroup{
    return @"/app/user/getMyGroupList.action";
}

+(NSString *)trainMyjoinGroup{
    return @"/app/user/getMyJoinGroup.action";
}
+(NSString *)trainMyManagerGroup{
    return @"/app/user/getMyManagerGroup.action";
}
/**
 * 圈子  详情
 */
+(NSString *)trainGroupInfo{
    return @"/app/user/getGroupInfo.action";
}

/**
 * 圈子  加入圈子
 */
+(NSString *)trainGroupJoin{
    return @"/app/user/joinGroup.action";
}

+(NSString *)trainTopic{
    return @"/app/user/getTopicList.action";
}

/**
 * 话题   我的话题list
 */
+(NSString *)trainMyTopic{
    return @"/app/user/getMytopicList.action";
}

/**
 * 话题   话题详情
 */
+(NSString *)trainTopicInfo{
    return @"/app/user/getTopicInfo.action";
}

/**
 * 话题   话题点赞
 */
+(NSString *)trainTopicTop{
    return @"/app/user/topTopic.action";
}

/**
 * 话题   话题收藏
 */
+(NSString *)trainTopicCollect{
    return @"/app/user/collectTopic.action";
}

/**
 * 话题   话题 回复
 */
+(NSString *)trainTopicPost{
    return @"/app/user/postTopic.action";
    
}

/**
 课程讨论 回复

 */
+(NSString *)trainCoursePost{
    return @"/app/user/postCoursePost.action";
    
}
/**
 * 话题   课程 添加新讨论
 */
+(NSString *)trainAddCourseTopic{
    return @"/app/user/insertd.action";
//    return @"/app/user/newInsertd.action";
}

/**
 * 话题   课程 添加新讨论
 */
+(NSString *)trainAddNewTopic{
    return @"/app/user/addTopic.action";
}
/**
 * 话题   上传话题的pic
 */
+(NSString *)trainuploadImage{
    return @"/app/user/uploadTopicPic.action";
}

/**
 * 话题   删除话题
 */
+(NSString *)trainRemoveTopic{
    return @"/app/user/removeTopic.action";
}

/**
 * 话题   删除话题的回复
 */
+(NSString *)trainRemoveTopicPost{
    return @"/app/user/removeTopicPost.action";
}



#pragma   mark - 文库
+(NSString *)trainDocument {
    return @"/app/user/getShareList.action";
//        return @"/app/user/share.action";

}

+(NSString *)trainmyDocument {
    //    return @"/app/user/getShareList.action";
    return @"/app/user/share.action";
    
}
/**
 * 文库   收藏文库
 */
+(NSString *)trainDocAddCollect {
    return @"/app/user/addDocOper.action";
}

/**
 * 文库   取消收藏文库
 */
+(NSString *)trainDocCancelCollect {
    return @"/app/user/cancelCollection.action";
}

/**
 * 文库   文库分类list
 */
+(NSString *)trainDocCategoryList {
    return @"/app/user/getDir123List.action";
}


#pragma   mark - 我的收藏
+(NSString *)trainMyCollectCourse {
    return @"/app/user/getMyCollect.action";
}
+(NSString *)trainMyCollectTopic {
    return @"/app/user/MycollectTopic.action";
}
+(NSString *)trainMyCollectDoc {
    return @"/app/user/MycollectTopic.action";
}
+(NSString *)trainMyCollect {
    return @"/app/user/getMyCollect.action";
}

#pragma   mark - 考试

/**
 * 考试   全部考试
 */
+(NSString *)trainALLExam {
    return @"/app/user/getAllExam.action";
}

/**
 * 考试   独立考试
 */
+(NSString *)trainExamIndependent {
    return @"/app/user/getIndependentExam.action";
}

/**
 * 考试   课程考试
 */
+(NSString *)trainExamCourse {
    return @"/app/user/getCourseExam.action";
}

/**
 * 考试   项目考试
 */
+(NSString *)trainExamClass {
    return @"/app/user/getClassExam.action";
}

/**
 * 考试   考试 回顾
 */
+(NSString *)trainExamReview {
    return @"/app/user/reviewExam.action";
}

/**
 * 考试   作业 or 调查  mobileExam.publish_key=WORK (作业) EVALUATE (问卷) SURVEY (调查)
 */
+(NSString *)trainExamList {
    return @"/app/user/getExam.action";
}


#pragma   mark - 我的笔记

+(NSString *)trainMyNote {
    return @"/app/user/getMyNotes.action";
}

/**
 * 我的笔记   编辑
 */
+(NSString *)trainMyNoteEdit {
    return @"/app/user/editNotes.action";
}

/**
 * 我的笔记   删除
 */
+(NSString *)trainMyNoteDelete {
    return @"/app/user/delNote.action";
}

#pragma   mark - 积分

/**
 * 积分   积分信息
 */
+(NSString *)trainIntegral {
    return @"/app/user/getMyIntegral.action";
}

/**
 * 积分  积分等级规则
 */
+(NSString *)trainIntegralLevel {
    return @"/app/user/getIntegralLevel.action";
}

/**
 * 积分  积分分数规则
 */
+(NSString *)trainIntegralRule {
    return @"/app/user/getIntegralRule.action";
}

#pragma   mark - 资讯

/**
 * 资讯分类
 */
+(NSString *)trainMessageCategory{
    return @"/app/user/findDynamicCategory.action";
}

/**
 * 资讯列表
 */
+(NSString *)trainMessageList {
    return @"/app/user/findDynamicList.action";
    
}

#pragma   mark - 消息中心


/**
 * 消息列表
 */
+(NSString *)trainNewsList {
    return @"/app/user/myMessage.action";
    
}

/**
 * 消息详情
 */
+(NSString *)trainNewsDetail {
    return @"/app/user/getMessageById.action";
    
}
/**
 * 读取消息
 */
+(NSString *)trainReadNews {
    return @"/app/user/readMessage.action";
    
}

//#pragma   mark - 消息
//+(NSString *)trainNews{
//    return @"/app/user/myMessage.action";
//}

///**
// * 将未读变成已读
// */
//+(NSString *)trainReadNews{
//    return  @"/app/user/readMessage.action";
//}


#pragma mark - 意见反馈 && 建议
/**
 意见反馈 && 建议
 */
+(NSString *)trainSendSuggest{
    return @"/app/user/addFeedBack.action";
}





@end
