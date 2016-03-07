//
//  UIView+SDAutoLayout.h
//
//  Created by gsd on 15/10/6.
//  Copyright (c) 2015年 gsd. All rights reserved.
//

/*
 *************************************************************************
 
 --------- INTRODUCTION ---------
 
 HOW TO USE ?
 
 MODE 1. >>>>>>>>>>>>>>> You can use it in this way:
 
 Demo.sd_layout
 .topSpaceToView(v1, 100)
 .bottomSpaceToView(v3, 100)
 .leftSpaceToView(v0, 150)
 .rightSpaceToView(v2, 150);
 
 MODE 2. >>>>>>>>>>>>>>> You can also use it in this way that is more brevity:
 
 Demo.sd_layout.topSpaceToView(v1, 100).bottomSpaceToView(v3, 100).leftSpaceToView(v0, 150).rightSpaceToView(v2, 150);
 
 
 *************************************************************************
 */


/*
 
 *********************************************************************************
 *
 * 在您使用此自动布局库的过程中如果出现bug请及时以以下任意一种方式联系我们，我们会及时修复bug并
 * 帮您解决问题。
 * QQ    : 2689718696(gsdios)
 * Email : gsdios@126.com
 * GitHub: https://github.com/gsdios
 * 新浪微博:GSD_iOS
 *
 * 视频教程：http://www.letv.com/ptv/vplay/24038772.html
 * 用法示例：https://github.com/gsdios/SDAutoLayout/blob/master/README.md
 *
 *********************************************************************************
 
 */

#import <UIKit/UIKit.h>

@class SDAutoLayoutModel;

typedef SDAutoLayoutModel *(^MarginToView)(UIView *toView, CGFloat value);
typedef SDAutoLayoutModel *(^Margin)(CGFloat value);
typedef SDAutoLayoutModel *(^MarginEqualToView)(UIView *toView);
typedef SDAutoLayoutModel *(^WidthHeight)(CGFloat value);
typedef SDAutoLayoutModel *(^WidthHeightEqualToView)(UIView *toView, CGFloat ratioValue);
typedef SDAutoLayoutModel *(^AutoHeight)(CGFloat ratioValue);
typedef void (^SpaceToSuperView)(UIEdgeInsets insets);

@interface SDAutoLayoutModel : NSObject

/*
 *************************说明************************
 
 方法名中带有“SpaceToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）间距数值
 方法名中带有“RatioToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）倍数
 方法名中带有“EqualToView”的需要传递1个参数：（UIView）参照view
 方法名中带有“Is”的需要传递1个参数：（CGFloat）数值
 
 *****************************************************
 */

/**设置距离其它view的"左"间距*/
@property (nonatomic, copy, readonly) MarginToView leftSpaceToView;
/**设置距离其它view的"右"间距*/
@property (nonatomic, copy, readonly) MarginToView rightSpaceToView;
/**设置距离其它view的"上"间距*/
@property (nonatomic, copy, readonly) MarginToView topSpaceToView;
/**设置距离其它view的"下"间距*/
@property (nonatomic, copy, readonly) MarginToView bottomSpaceToView;

/**设置x 值*/
@property (nonatomic, copy, readonly) Margin xIs;
/**设置y 值*/
@property (nonatomic, copy, readonly) Margin yIs;
/**设置centerX 值*/
@property (nonatomic, copy, readonly) Margin centerXIs;
/**设置centerY 值*/
@property (nonatomic, copy, readonly) Margin centerYIs;
/**设置width 值*/
@property (nonatomic, copy, readonly) WidthHeight widthIs;
/**设置height 值*/
@property (nonatomic, copy, readonly) WidthHeight heightIs;
/**设置最大宽度*/
@property (nonatomic, copy, readonly) WidthHeight maxWidthIs;
/**设置最大高度*/
@property (nonatomic, copy, readonly) WidthHeight maxHeightIs;
/**设置最小宽度*/
@property (nonatomic, copy, readonly) WidthHeight minWidthIs;
/**设置最小高度*/
@property (nonatomic, copy, readonly) WidthHeight minHeightIs;


/**设置和哪一个参照view的"左"边距相同*/
@property (nonatomic, copy, readonly) MarginEqualToView leftEqualToView;
/**设置和哪一个参照view的"右"边距相同*/
@property (nonatomic, copy, readonly) MarginEqualToView rightEqualToView;
/**设置和哪一个参照view的"上"边距相同*/
@property (nonatomic, copy, readonly) MarginEqualToView topEqualToView;
/**设置和哪一个参照view的"下"边距相同*/
@property (nonatomic, copy, readonly) MarginEqualToView bottomEqualToView;
/**设置和哪一个参照view的"x轴"相同*/
@property (nonatomic, copy, readonly) MarginEqualToView centerXEqualToView;
/**设置和哪一个参照view的"y轴"相同*/
@property (nonatomic, copy, readonly) MarginEqualToView centerYEqualToView;

/**设置宽度等于参照view的多少倍(参照view,倍数(0~1))*/
@property (nonatomic, copy, readonly) WidthHeightEqualToView widthRatioToView;
/**设置高度等于参照view的多少倍(参照view,倍数(0~1))*/
@property (nonatomic, copy, readonly) WidthHeightEqualToView heightRatioToView;
/**自使用高度(输入：0)*/
@property (nonatomic, copy, readonly) AutoHeight autoHeightRatio;
/**填充父view(快捷方法)(UIEdgeInsetsZero)*/
@property (nonatomic, copy, readonly) SpaceToSuperView spaceToSuperView;

@property (nonatomic, weak) UIView *needsAutoResizeView;

@end




@interface UIView (SDAutoHeight)

@property (nonatomic) CGFloat autoHeight;

@property (nonatomic) UIView *sd_bottomView;
@property (nonatomic) CGFloat sd_bottomViewBottomMargin;

/**设置普通view内容自适应*/
- (void)setupAutoHeightWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

@end

@interface UIView (SDLayoutExtention)

/**设置圆角*/
@property (nonatomic, strong) NSNumber *sd_cornerRadius;
/**设置圆角*/
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromWidthRatio;
/**设置圆角*/
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromHeightRatio;

/**设置等宽子view*/
@property (nonatomic, strong) NSArray *sd_equalWidthSubviews;

@end


@interface UIScrollView (SDAutoContentSize)

/**设置scrollview内容自适应*/
- (void)setupAutoContentSizeWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

@end


@interface UILabel (SDLabelAutoResize)

/**设置单行文本label宽度自适应*/
- (void)setSingleLineAutoResizeWithMaxWidth:(CGFloat)maxWidth;

@end



































// ----------------- 以下为此库内部需要用到的类和方法（可以不用看）----------------

@interface SDAutoLayoutModelItem : NSObject

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, weak) UIView *refView;

@end

@interface UIView (SDAutoLayout)

- (NSMutableArray *)autoLayoutModelsArray;

- (SDAutoLayoutModel *)sd_layout;

- (void)addAutoLayoutModel:(SDAutoLayoutModel *)model;

@property (nonatomic, strong) NSNumber *fixedWith;
@property (nonatomic, strong) NSNumber *fixedHeight;

@property (nonatomic, strong) NSNumber *sd_maxWidth;

@property (nonatomic, strong) NSNumber *autoHeightRatioValue;

@end


@interface UIView (SDChangeFrame)

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) CGFloat centerX;
@property (nonatomic) CGFloat centerY;

@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;


@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize size;

@end
