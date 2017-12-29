//
//  SegmentUtils.h
//  CloudMonitor
//
//  Created by 黄梓伦 on 29/12/2017.
//  Copyright © 2017 STS. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 *
 *  直接导入"HZLFrame.h" 会出现CGHZLFrameMake符号重定义的链接器错误，所以将CGHZLFrameMake函数声明和定义放在实现函数的文件中或者将实现放在.m文件中
 */
#if 0
#import "HZLFrame.h"
#endif

/**
 只包含原点及高度的结构体
 */
typedef struct OriginAndHeight{
    
    CGFloat originX;
    CGFloat originY;
    CGFloat SizeHeight;
    
}XYHeightFrame;
XYHeightFrame CGXYHeightFrameMake(CGFloat x, CGFloat y, CGFloat height);


@interface SegmentUtils : UIView

@property (nonatomic, strong) NSArray *items; //按钮标题数组，数组内元素为字符串

@property (nonatomic, assign) NSInteger selectedIndex; //当前选中按钮的Index

@property (nonatomic, assign) CGFloat fontSize; //字体大小

@property (nonatomic, strong) UIColor *selectedColor; //按钮选中状态的标题文字颜色

@property (nonatomic, strong) UIColor *titleColor; //按钮未选中状态的标题文字颜色

@property (nonatomic, assign) CGFloat currentXOffset; //Segment在X方向的偏移量，即当前选中的按钮的center的X坐标


/**
 根据Segment总标题文字长度及字体自适应宽度 字体固定为15号

 @param frame 需要生成的Segment的原点及高度，类型为XYHeightFrame结构体
 @param items Segement的标题数组，数组元素为字符串类型
 @return 根据Segment总标题文字长度及字体自适应宽度
 */
- (instancetype)initWithFlexibleWidthFrame:(XYHeightFrame)frame items:(NSArray *)items;

/**
 根据Segment总标题文字长度及字体自适应宽度

 @param frame 需要生成的Segment的原点及高度，类型为XYHeightFrame结构体
 @param items Segement的标题数组，数组元素为字符串类型
 @param fontSize 字体大小
 @return 根据Segment总标题文字长度及字体自适应宽度
 */
- (instancetype)initWithFlexibleWidthFrame:(XYHeightFrame)frame items:(NSArray *)items fontSize:(CGFloat)fontSize;


/**
 传入标题字符串生成Segment

 @param frame Segment的Frame
 @param items 标题数组
 @return 生成的Segment
 */
- (instancetype)initWithFrame:(CGRect)frame items:(NSArray *)items;

/**
 Segment的响应事件

 @param target 响应事件的Target
 @param action 响应事件的方法编号SEL
 */
- (void)addTarget:(id)target withAction:(SEL)action;

@end
